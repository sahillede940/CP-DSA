// TIME: 03:58:02 07/08/2023

// Day 1 Sprinklr Question
// Flower and Houses
/*

....H.....
..........
..H.......
.H.H......
..H.......
.....H....
..........
..........
..........
..........

*/

#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "D:\VSCODE\DEBUG.h"
// #endif

#define sahil main
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007 // 998244353
#define kout(_arg) cout << _arg << '\n'
#define print(_arg) cout << #_arg << " = " << _arg << '\n'
#define YES kout("YES")
#define NO kout("NO")

using pii = pair<int, int>;
int n, m, x, y;
vector<int> v;
vector<string> g;
const int N = 10;
int row[N], col[N];
vector<pii> H;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool check(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N || row[x] || col[y] || g[x][y] != '.')
		return false;
	return true;
}

bool ans = false;
void solve(int lvl)
{
	if (ans)
		return;
	//  base case
	if (lvl == H.size())
	{
		ans = true;
		return;
	}

	int x = H[lvl].first, y = H[lvl].second;
	// transition
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny))
		{
			g[nx][ny] = 'F';
			row[nx] = 1, col[ny] = 1;

			// lvl + 1
			solve(lvl + 1);

			g[nx][ny] = '.';
			row[nx] = 0, col[ny] = 0;
		}
	}
}

signed sahil()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n = N;
	// cin >> n;
	g.resize(n);
	for (int i = 0; i < 10; i++)
	{
		row[i] = col[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
		for (int j = 0; j < n; j++)
		{
			if (g[i][j] == 'H')
				H.pb({i, j});
		}
	}

	solve(0);
	cout << ans;

	return 0;
}