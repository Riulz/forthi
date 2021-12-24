#include <bits/stdc++.h>
using namespace std;
int n, a[100], k;
void display()
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void gen_permutation()
{
    int t = n - 1;
    while (t > 0 && a[t - 1] > a[t])
        --t;
    if (t == 0)
        return;
    int i = n - 1;
    while (a[i] < a[t - 1])
        --i;
    swap(a[i], a[t - 1]);
    int l = t, r = n - 1;
    while (l < r)
        swap(a[l++], a[r--]);
    display();
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i)
    {
        gen_permutation();
    }
    return 0;
}