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
#define F first
#define S second
using edge = pair<int, pair<int, int>>;

int n, m, x, y, z;
vector<int> v;
vector<vector<int>> g;
int cnt = 0;

/*

6 8
1 2 11
1 6 9
1 3 10
2 3 12
6 5 2
3 5 3
3 4 10
5 4 36

ans 

cnt = 43
edge: 6 5 wt= 2
edge: 3 5 wt= 3
edge: 1 6 wt= 9
edge: 3 4 wt= 10
edge: 1 2 wt= 11

Total Cost = 35

*/

vector<int> par, sizes;

void basic_init()
{
    vector<edge> g;
    vector<edge> gnew;
    par.resize(n + 1);
    sizes.resize(n + 1);
    g.resize(m);
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        sizes[i] = 1;
    }
}

int f_par(int x)
{
    cnt++;
    if (par[x] == x)
        return x;
    return par[x] = f_par(par[x]);
}

void unite(int x, int y)
{
    int rx = f_par(x), ry = f_par(y);
    if (sizes[rx] < sizes[ry])
        swap(rx, ry);
    sizes[rx] += sizes[ry];
    par[ry] = rx;
}

void print_g(vector<edge> &g)
{
    int cost = 0;
    for (auto vv : g)
    {
        cout << "edge: " << vv.S.F << " " << vv.S.S << " wt= " << vv.F << '\n';
        cost += vv.F;
    }
    cout << "\nTotal Cost = " << cost << '\n';
}

signed sahil()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    basic_init();
    for (int i = 0; i < m; i++)
    {
        cin >> g[i].S.F >> g[i].S.S >> g[i].F;
    }
    sort(g.begin(), g.end());

    for (auto next : g)
    {
        int a = next.S.F, b = next.S.S;
        if (f_par(a) != f_par(b))
        {
            gnew.push_back(next);
            unite(a, b);
        }
    }
    print(cnt);
    print_g(gnew);

    return 0;
}