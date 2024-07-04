#include <bits/stdc++.h>
using namespace std;

#define sahil main
#define ll long long
#define int long long
#define mod 1000000007 // 998244353
#define kout(_arg) cout << _arg << '\n'
#define print(_arg) cout << #_arg << " = " << _arg << '\n'
#define YES kout("YES")
#define NO kout("NO")

int n, m, x, y;
vector<int> topo, indeg;
vector<vector<int>> g;

// lexiographically smallest topological order

void kahn()
{
    priority_queue<int> line;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            line.push(-i);
    }
    while (!line.empty())
    {
        int cur = -line.top();
        line.pop();
        topo.push_back(cur);
        for (auto next : g[cur])
        {
            indeg[next]--;
            if (indeg[next] == 0)
                line.push(-next);
        }
    }
}

signed sahil()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }

    kahn();

    if (topo.size() != n)
        kout(-1);
        
    else
    {
        for (int i = 0; i < n; i++)
            cout << topo[i] << ' ';
        cout << '\n';
    }

    return 0;
}