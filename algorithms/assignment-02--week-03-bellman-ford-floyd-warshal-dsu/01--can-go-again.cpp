#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int V, E_count;
    cin >> V >> E_count;
    vector<Edge> edges;

    while (E_count--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    int s;
    cin >> s;
    vector<long> dist(V + 1, LONG_MAX);
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (Edge e : edges)
        {
            int u = e.u, v = e.v, w = e.w;
            if (dist[u] != LONG_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool cycle = false;
    for (Edge e : edges)
    {
        int u = e.u, v = e.v, w = e.w;
        if (dist[u] != LONG_MAX && dist[u] + w < dist[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int T;
        cin >> T;
        while (T--)
        {
            int t;
            cin >> t;
            if (dist[t] == LONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[t] << endl;
            }
        }
    }

    return 0;
}
