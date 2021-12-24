#include <bits/stdc++.h>
using namespace std;
typedef struct Stuff
{
    double value, weight;
} st;
st ds[100];
int a[100], n, sigma = 0, b, FOPT = -INT_MAX;
void Branch_And_Bound(int k)
{
    for (int i = b / ds[k].weight; i >= 0; --i)
    {
        a[k] = i;
        sigma += ds[k].value * a[k];
        b -= ds[k].weight * a[k];
        if (k == n - 1)
        {
            FOPT = sigma;
        }
        else if (sigma + (ds[k + 1].value * b / ds[k + 1].weight) > FOPT)
        {
            Branch_And_Bound(k + 1);
        }
        sigma -= ds[k].value * a[k];
        b += ds[k].weight * a[k];
    }
}
bool cmp(st a, st b)
{
    return a.value / a.weight > b.value / b.weight;
}
int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> ds[i].value >> ds[i].weight;
    }
    sort(ds, ds + n, cmp);
    Branch_And_Bound(0);
    cout << FOPT;
}
//  4 8 10 5 5 3 3 2 6 4