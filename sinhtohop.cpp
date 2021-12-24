#include <iostream>
#include <math.h>
using namespace std;

void out(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i];
    }
    cout << " ";
}

void gen(int a[], int n, int k)
{
    int t = k - 1;
    while (a[t] == n - k + t + 1)
    {
        --t;
    }
    ++a[t];
    for (int i = t + 1; i <= k; ++i)
    {
        a[i] = a[t] + i - t;
    }
}
int check(int a[], int n, int k)
{
    if (a[0] == n - k + 1)
        return 0;
    else
        return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k];
        for (int i = 0; i < k; ++i)
            a[i] = i + 1;
        while (true)
        {
            out(a, k);
            if (a[0] == n - k + 1)
                break;
            gen(a, n, k);
        }
        cout << endl;
    }
}