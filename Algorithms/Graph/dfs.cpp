// DFS
// input 6 6 1 2 1 3 3 4 3 5 2 6 6 7
// input 6 9 1 3 1 5 3 5 3 4 3 6 3 2 2 6 4 6 5 6
/*
input
6
4
1 2
2 3
1 3
4 5
*/
// time complexity O(v + 2*e)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];
bool visited[N] = {false};
int cnt_iteration = 0;

void dfs(int vertex)
{
    cnt_iteration++;
    if (visited[vertex])
        return;
    visited[vertex] = true;
    cout << vertex << endl;
    for (auto child : g[vertex])
    {
        cout << "parent: " << vertex << ", child: " << child << endl;
        dfs(child);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << "Total connected components: " << cnt << endl;
    cout << "count: " << cnt_iteration << endl;
    return 0;
}