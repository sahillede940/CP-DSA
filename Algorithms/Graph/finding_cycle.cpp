/*

Finding cycle in the graph and printing any one

11 11
4 5
2 4
4 9
9 10
10 11
10 6
6 7
7 5
7 8
8 3
3 1
NO

8 9
0 2
2 3
3 4
4 5
5 1
1 0
3 6
6 7
4 7
YES 0->2->3->4->5->1

8 9
2 0
2 3
3 4
4 5
5 1
1 0
3 6
6 7
4 7
NO

*/
#include <bits/stdc++.h>
using namespace std;
#define print(_arg) cout << #_arg << " = " << _arg << '\n'

vector<vector<int>> v;
vector<int> vis, cycle;
vector<int> parent;
bool cycle_found = false;
int no_of_times_dfs_called = 0;

void dfs(int node, int par)
{
	no_of_times_dfs_called++;
	if (cycle_found)
		return;
	parent[node] = par;
	vis[node]++;
	for (auto next : v[node])
	{
		if (vis[next] == 0)
		{
			dfs(next, node);
		}
		else if (vis[next] == 1)
		{
			cycle_found = true;
			int temp = node;
			while (temp != next)
			{
				cycle.push_back(temp);
				temp = parent[temp];
			}
			cycle.push_back(temp);
			return;
		}
	}
	vis[node] = 2;
}

signed main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, m, x, y;
	cin >> n >> m;
	v.resize(n + 1);
	parent.resize(n + 1);
	vis.assign(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
			dfs(i, i);
	}
	print(no_of_times_dfs_called);
	if (cycle_found)
	{
		cout << "YES ";
		for (int i = (int)cycle.size() - 1; i > -1; i--)
		{
			cout << cycle[i];
			if (i != 0)
				cout << "->";
		}
		cout << endl;
	}
	else
		cout << "NO" << '\n';

	v.clear();
	vis.clear();
	return 0;
}