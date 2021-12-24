#include <bits/stdc++.h>
using namespace std;
int a[1000], n, check[1000] = {0};
void backtrack(int i)
{
    for (int j = 1; j <= n; ++j)
    {
        if (!check[j])
        {
            a[i] = j;
            check[j] = 1;
            if (i == n)
            {
                result(a, n);
            }
            else
                backtrack(i + 1);
            check[j] = 0;
        }
    }
}
void result(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    cin >> n;
    backtrack(1);
}
