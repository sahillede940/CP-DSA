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

/*

10
1 2
2 3
2 4
1 9
1 6
6 8
6 5
6 7
9 10
6

*/

int n, m, x, y;
vector<int> v;
vector<vector<int>> g;
vector<int> parent_of, depth;

void init()
{
    parent_of.resize(n + 1);
    g.resize(n + 1);
    depth.resize(n + 1);
}

void dfs(int nn, int pp, int dd)
{
    parent_of[nn] = pp;
    depth[nn] = dd;

    for (auto next : g[nn])
    {
        if (pp != next)
        {
            dfs(next, nn, dd + 1);
        }
    }
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
    int end_point = x;
    for (int  i = 1; i <= n ; i++)
    {
        if(depth[i] > depth[end_point]){
            end_point = i;
        }
    }
    dfs(end_point, 0, 0);
    for (int  i = 1; i <= n ; i++)
    {
        if(depth[i] > depth[end_point]){
            end_point = i;
        }
    }
    cout << depth[end_point] + 1;


    return 0;
}