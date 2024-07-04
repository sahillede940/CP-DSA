// TIME: 00:47:22 22/05/2023

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long
#define mod 1000000007
// #define mod 998244353
#define INF 1e9
#define WOW                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Scissor  S - 0 -> 1
// Paper    P - 1 -> 2
// Stone    H - 2 -> 0

int a[1001];
int dp[1010][3][1010];
int track[1010][3][1010];

int n, k;
map<char, int> mp;
map<int, char> rmp;
string final_string = "";

int check(int my_move, int comp_move)
{
    return (comp_move == (my_move + 1) % 3);
}

int rec(int posi, int last, int change_left)
{

    // pruning
    if (change_left < 0)
        return -INF;

    // base case
    if (posi == n)
        return 0;

    // cache check
    if (dp[posi][last][change_left] != -1)
        return dp[posi][last][change_left];

    // transition
    int ans = -1e9;
    for (int my_move = 0; my_move < 3; my_move++)
    {
        int temp = check(my_move, a[posi]) + rec(posi + 1, my_move, change_left - (my_move == last ? 0 : 1));
        if (ans < temp)
        {
            ans = temp;
            track[posi][last][change_left] = my_move;
        }
    }

    // save and return
    return dp[posi][last][change_left] = ans;
}

void generate_string(int posi, int last, int change_left)
{
    if (posi == n)
        return;
    int my_move = track[posi][last][change_left];
    final_string += rmp[my_move];
    generate_string(posi + 1, my_move, change_left - ((last == my_move) ? 0 : 1));
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    memset(track, -1, sizeof(track));
    final_string = "";
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = mp[s[i]];
    }

    int max_i = -1;

    int ans = -1e9;
    for (int i = 0; i < 3; i++)
    {
        int temp = rec(0, i, k);
        if (ans < temp)
        {
            ans = temp;
            max_i = i;
        }
    }
    cout << ans << '\n';
    final_string = rmp[max_i];
    generate_string(1, max_i, k);
    cout << final_string << '\n';
}

signed main()
{
    WOW;
    int _T = 1;
    cin >> _T;

    mp['P'] = 0;
    mp['R'] = 1;
    mp['S'] = 2;

    rmp[0] = 'P';
    rmp[1] = 'R';
    rmp[2] = 'S';

    while (_T--)
        solve();
    return 0;
}