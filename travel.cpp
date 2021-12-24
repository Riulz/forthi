#include <bits/stdc++.h>
using namespace std;
int n, t = 0, a[100], use[100] = {};
int price[100][100] = {}, min_price = INT_MAX;
int FOPT = INT_MAX, FOPT_Arr[100];
void Branch_And_Bounce(int i)
{
    for (int j = 1; j <= n; ++j)
    {
        if (!use[j])
        {
            a[i] = j;
            use[j] = 1;
            t += price[a[i - 1] - 1][a[i] - 1];
            if (i == n - 1)
            {
                if (t + price[a[i] - 1][a[0] - 1] < FOPT)
                {
                    a[i + 1] = a[0];
                    FOPT = t + price[a[i] - 1][a[0] - 1];
                    copy(a, a + n + 1, FOPT_Arr);
                }
            }
            else if (t + (n - i) * min_price < FOPT)
            {
                Branch_And_Bounce(i + 1);
            }
            t -= price[a[i - 1] - 1][a[i] - 1];
            use[j] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> price[i][j];
            if (price[i][j] < min_price)
                min_price = price[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[0] = i;
        use[i] = 1;
        Branch_And_Bounce(1);
        use[i] = 0;
    }

    cout << "Price : " << FOPT << endl;
    for (int i = 0; i <= n; ++i)
    {
        cout << FOPT_Arr[i] << " ";
    }
    return 0;
}
// 0 3 14 18 15
// 3 0 4 22 20
// 17 9 0 16 4
// 6 3 7 0 12
// 9 15 11 5 0
// OUTPUT : 22 ( 1,2,3,5,4,1 )