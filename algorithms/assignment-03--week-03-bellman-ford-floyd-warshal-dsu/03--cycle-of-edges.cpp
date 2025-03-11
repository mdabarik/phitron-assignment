#include <bits/stdc++.h>
using namespace std;
int leader[1000005], group_size[1000005];

int find_dsu(int node)
{
    if (leader[node] == -1)
        return node;
    int root = find_dsu(leader[node]);
    leader[node] = root;
    return root;
}

void union_dsu(int leader1, int leader2)
{
    int root1 = find_dsu(leader1);
    int root2 = find_dsu(leader2);

    if (root1 == root2)
        return;

    if (group_size[root1] >= group_size[root2])
    {
        group_size[root1]++;
        leader[root2] = root1;
    }
    else
    {
        group_size[root2]++;
        leader[root1] = root2;
    }
}

bool is_cycle(int leader[], int leader1, int leader2)
{
    int root1 = find_dsu(leader1);
    int root2 = find_dsu(leader2);
    return root1 == root2;
}

int main()
{
    int V, E;
    cin >> V >> E;

    memset(leader, -1, sizeof(leader));
    memset(group_size, 1, sizeof(group_size));

    int count = 0;
    while (E--)
    {
        int leader1, leader2;
        cin >> leader1 >> leader2;
        if (is_cycle(leader, leader1, leader2))
        {
            count++;
        }
        union_dsu(leader1, leader2);
    }

    cout << count << endl;

    return 0;
}
