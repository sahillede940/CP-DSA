// TIME: 15:21:01 22/06/2023

/*
10 11
###########
#....#...##
#....#...##
#....######
######....#
#....######
#....#....#
###########
#....#....#
###########

*/

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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, cnt = 0;
vector<vector<bool>> vis;
vector<string> v;

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == '#')
        return false;
    return true;
}

void dfs(int x, int y)
{
    if (v[x][y] == '#')
        return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

void testcase()
{
    cin >> n >> m;
    vis.assign(n, vector<bool>(m, false));
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && v[i][j] == '.')
            {
                dfs(i, j);
                cnt++;
            }
            
    cout << cnt << '\n';
}

signed sahil()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    // fact();
    int __ = 1;
    // cin >> __;
    while (__--)
        testcase();
    return 0;
}