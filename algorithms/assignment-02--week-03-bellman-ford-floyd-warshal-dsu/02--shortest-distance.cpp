#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    long adj[1005][1005];

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            adj[i][j] = LONG_MAX;
        }
        adj[i][i] = 0;
    }

    while (E--)
    {
        int u, v;
        cin >> u >> v;
        long cost;
        cin >> cost;
        adj[u][v] = min(adj[u][v], cost);
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (adj[i][k] == LONG_MAX || adj[k][j] == LONG_MAX)
                    continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int u, v;
        cin >> u >> v;
        if (adj[u][v] == LONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[u][v] << endl;
        }
    }

    return 0;
}
