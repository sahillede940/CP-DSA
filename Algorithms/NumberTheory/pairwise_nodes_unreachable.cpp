/* FIND PAIRWISE NODES WHICH ARE UNREACHABLE */

/*

Test Case :
7 5
0 2 0 5 2 4 1 6 5 4

Ans:
14

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> sizes;
vector<vector<int>> v;
vector<bool> vis;

const int mod = 1e9 + 7;

ll fac[100100];

int oo = 0;

int nCr(int a, int b, int mod)
{
	return (a * a - a) / 2;
}

void dfs(int x, int &cnt)
{
	oo++;

	vis[x] = true;
	cnt++;

	for (auto next : v[x])
	{
		if (!vis[next])
			dfs(next, cnt);
	}
}

signed main()
{
	int n, m;
	cin >> n >> m;
	v.resize(n);
	vis.assign(n, false);

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			int cnt = 0;
			dfs(i, cnt);
			sizes.push_back(cnt);
		}
	}
	ll total = nCr(n, 2, mod);
	for (auto temp : sizes)
	{
		total -= nCr(temp, 2, mod);
	}
	cout << total << ' ' << oo << '\n';
	return 0;
}