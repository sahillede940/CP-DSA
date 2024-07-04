#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dep;
vector<vector<int>> g;
int n;

void init()
{
    dep.resize(n + 1);
    g.resize(n + 1);

    int x, y;
    for (int  i = 0; i < n-1 ; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
}

void dfs(int nn, int pp, int dd)
{
    dep[nn] = dd;
    for (auto vv : g[nn])
        if (vv != pp)
            dfs(vv, nn, dd + 1);
}



signed main()
{
    cin >> n;
    init();

    dfs(1, 1, 0);
    int ep1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] > dep[ep1])
            ep1 = i;
    }
    dfs(ep1, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] > dep[ep1])
            ep1 = i;
    }
    cout << "dia: " << dep[ep1];
    return 0;
}