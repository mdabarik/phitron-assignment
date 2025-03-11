#include <bits/stdc++.h>
using namespace std;

int dp[100005];

bool recursion(int n, int curr)
{
    if (curr > n)
        return false;
    if (curr == n)
        return true;

    if (dp[curr] != -1)
        return dp[curr];

    bool op1 = recursion(n, curr + 3);
    bool op2 = recursion(n, curr * 2);

    dp[curr] = op1 || op2;
    return dp[curr];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        memset(dp, -1, sizeof(dp));

        if (recursion(n, 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
