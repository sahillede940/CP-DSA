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

/*
Finding shortest distance with S and E

8 11
S.#...#...#
..#.#...#..
#...#####.#
E####..#...
....#.####.
...##......
.#....##.#.
...###...#.

ans :
total_no_of_operation_bfs_took = 140
{3,0} = 25
{3,2} = 27
{6,3} = 17
{7,7} = -1

*/

int n, m;
const int oo = 1e9 + 1000;
vector<string> v;
int walls = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool inside(pair<int, int> node)
{
	int x = node.first, y = node.second;
	if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == '#')
		return false;
	return true;
}

// time complexity = O(n*m*4 - walls * 4 - unvisited * 4)

vector<vector<int>> dist;
vector<vector<pair<int, int>>> parent;
int total_no_of_operation_bfs_took = 0;
void bfs(pair<int, int> start)
{
	dist.assign(n, vector<int>(m, oo));
	parent.assign(n, vector<pair<int, int>>(m));
	dist[start.first][start.second] = 0;
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		int cur_dist = dist[cur.first][cur.second];
		for (int k = 0; k < 4; k++)
		{
			total_no_of_operation_bfs_took++;
			pair<int, int> next = {cur.first + dx[k], cur.second + dy[k]};
			if (inside(next) && dist[next.first][next.second] > (cur_dist + 1))
			{
				dist[next.first][next.second] = cur_dist + 1;
				parent[next.first][next.second] = cur;
				q.push(next);
			}
		}
	}
}

signed sahil()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	v.resize(n);

	pair<int, int> st;
	pair<int, int> ends;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '#')
				walls++;
			else if (v[i][j] == 'S')
				st = {i, j};
			else if (v[i][j] == 'E')
				ends = (make_pair(i, j));
		}
	}
	cout << '\n';

	bfs(st);
	print(walls);
	print(total_no_of_operation_bfs_took);
	cout << '{' << ends.first << ',' << ends.second << "} = " << (dist[ends.first][ends.second] == oo ? -1 : dist[ends.first][ends.second]) << '\n';
	if (dist[ends.first][ends.second] != oo)
	{
		vector<pair<int, int>> path;
		pair<int, int> temp = ends;
		while (temp != st)
		{
			path.push_back(temp);
			temp = parent[temp.first][temp.second];
		}
		path.push_back(temp);
		reverse(path.begin(), path.end());
		// pr(path);
		for (auto node : path)
		{
			cout << "{" << node.second << "," << node.first << "}" << (node == path[path.size() - 1] ? "" : " -> ");
		}
		cout << '\n';
	}

	return 0;
}