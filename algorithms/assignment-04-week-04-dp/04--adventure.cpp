#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
        return 0;

    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    if (weight[i] <= max_weight)
    {
        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, max_weight);
        dp[i][max_weight] = max(op1, op2);
    }
    else
    {
        dp[i][max_weight] = knapsack(i - 1, max_weight);
    }

    return dp[i][max_weight];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, max_w;
        cin >> n >> max_w;

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            cin >> weight[i];

        for (int i = 0; i < n; i++)
            cin >> val[i];

        int res = knapsack(n - 1, max_w);
        cout << res << endl;
    }

    return 0;
}
