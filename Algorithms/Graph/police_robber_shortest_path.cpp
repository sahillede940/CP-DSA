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
#define pii pair<int, int>

/*

find shortest path for robber, escape from police

// grid size
9 7
// grid
.......
.R..W..
..WW...
....P..
.......
....P..
..P.P..
.......
.....B.
//  no of police
4
// police x and y coordi and direction of his eye
6 5 U
7 5 R
4 5 L
7 3 L


9 7
.......
.R..W..
..WW...
....P..
.......
....P..
..P.P..
.......
.....B.
4
6 5 U
7 5 R
4 5 L
7 3 L

*/

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct posi
{
    int x, y;
    char direc;
};

int n, m, total_police;
pair<int, int> robber, bank;
vector<string> g; // grid
vector<vector<int>> dist;
map<char, pair<int, int>> mp; // store directions
vector<pair<int, int>> police_coordi;

const int oo = 1e9 + 100;

bool check_for_police(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'W')
        return false;
    return true;
}

bool police_check(char x)
{
    if (x == 'L' || x == 'R' || x == 'U' || x == 'D')
        return true;
    return false;
}

bool check_for_robber(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*' || g[x][y] == 'W' || police_check(g[x][y]))
        return false;
    return true;
}

void print_grid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (police_check(g[i][j]) || g[i][j]=='W')
                cout << '*';
            else
                cout << g[i][j];
        }
        cout << '\n';
    }
}

void vision_path_marker()
{
    for (int i = 0; i < police_coordi.size(); i++)
    {
        int x = police_coordi[i].first, y = police_coordi[i].second;
        char direc = g[x][y];
        x += mp[direc].first;
        y += mp[direc].second;
        while (check_for_police(x, y))
        {
            if (g[x][y] == direc)
                break;
            else if (!police_check(g[x][y]))
                g[x][y] = '*';

            x += mp[direc].first;
            y += mp[direc].second;
        }
    }
}

void bfs()
{
    dist.assign(n, vector<int>(m, oo));
    dist[robber.first][robber.second] = 0;

    queue<pii> line;
    line.push(robber);

    while (!line.empty())
    {
        pii cur = line.front();
        line.pop();
        int cur_dist = dist[cur.first][cur.second];
        for (int i = 0; i < 4; i++)
        {
            pii next = {cur.first + dx[i], cur.second + dy[i]};
            if (check_for_robber(next.first, next.second) && dist[next.first][next.second] > cur_dist + 1)
            {
                dist[next.first][next.second] = cur_dist + 1;
                line.push(next);
            }
        }
    }
}

signed sahil()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};

    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
                robber = {i, j};
            else if (g[i][j] == 'B')
                bank = {i, j};
            else if (police_check(g[i][j]))
                police_coordi.push_back({i, j});
        }
    }

    vision_path_marker();
    bfs();
    print_grid();

    if (dist[bank.first][bank.second] != oo)
        kout(dist[bank.first][bank.second]);
    else
        kout(-1);

    return 0;
}