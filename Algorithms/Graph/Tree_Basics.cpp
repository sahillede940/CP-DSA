#include <bits/stdc++.h>
using namespace std;

#define sahil main
#define ll long long
#define int long long
#define mod 1000000007 // 998244353
#define kout(_arg) cout << _arg << '\n'
#define print(_arg) cout << #_arg << " : \t\t" << _arg << '\n'
#define YES kout("YES")
#define NO kout("NO")
#define pb push_back

int n, m, x, y;
vector<int> v;
vector<vector<int>> g;
vector<int> parent_of, depth, subtree_sz, num_child, is_leaf;

void init()
{
    parent_of.resize(n + 1);
    g.resize(n + 1);
    depth.resize(n + 1);
    subtree_sz.resize(n + 1);
    num_child.resize(n + 1);
    is_leaf.resize(n + 1);
}

void dfs(int nn, int pp, int dd)
{
    parent_of[nn] = pp;
    depth[nn] = dd;
    subtree_sz[nn] = 1;
    num_child[nn] = 0;

    for (auto next : g[nn])
    {
        if (pp != next)
        {
            num_child[nn]++;
            dfs(next, nn, dd + 1);
            subtree_sz[nn] += subtree_sz[next];
        }
    }
    if (num_child[nn] == 0)
        is_leaf[nn] = 1;
}

signed sahil()
{
    // ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    init();
    for (int i = 0; i < (n - 1); i++)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cin >> x;
    dfs(x, 0, 0);
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        print(is_leaf[x]);
        print(subtree_sz[x]);
        print(num_child[x]);
        print(depth[x]);
        print(parent_of[x]);
    }

    return 0;
}