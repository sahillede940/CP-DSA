#include <bits/stdc++.h>
using namespace std;

#define sahil main
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007 // 998244353
#define kout(_arg) cout << _arg << '\n'
#define print(_arg) cout << #_arg << " = " << _arg << '\n'
#define YES kout("YES")
#define NO kout("NO")

#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

int n, m, x, y;
vector<int> out_order, vis, scc_no;
vector<vector<int>> g, g_rev;
vector<vector<int>> g_condensed; //  we can keep this as set ( vector<set<int>> ) to remove dupletion
int cur_scc_no = 0;

void init()
{
    g.resize(n + 1);
    g_rev.resize(n + 1);
    scc_no.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].pb(y);
        g_rev[y].pb(x);
    }
}
/*
9 10
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
8 7
9 8

*/
void dfs_g(int x) // for out_order
{
    vis[x] = 1;
    for (auto vv : g[x])
    {
        if (!vis[vv])
            dfs_g(vv);
    }
    // push x inside to get out time order
    out_order.pb(x);
}

void dfs_g_rev(int x) // for out_order
{
    vis[x] = 1;
    // mark scc no
    scc_no[x] = cur_scc_no;
    for (auto vv : g_rev[x])
    {
        if (!vis[vv])
            dfs_g_rev(vv);
    }
}

signed sahil()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    // take g input and make g revered graph
    init();
    // make vector {out_order} of node which represent which node got exited first using dfs
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs_g(i);
    }

    reverse(out_order.begin(), out_order.end()); // reverse order of timeline
    // clear visited array
    vis.assign(n + 1, 0);
    // call dfs on reversed graph and mark all node in same dfs as same comp
    for (int i : out_order)
    {
        if (!vis[i])
        {
            cur_scc_no++;
            dfs_g_rev(i);
        }
    }
    print(cur_scc_no);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " => " <<scc_no[i] << '\n';
    }
    // by this time we got which node belongs to which component
    // Now we have to create a new condensed graph
    g_condensed.resize(cur_scc_no + 1);
    for (int i = 1; i <= n; i++)
        for (auto vv : g[i])
            if (scc_no[i] != scc_no[vv])
                g_condensed[scc_no[i]].pb(scc_no[vv]);

    pr(g_condensed);

    return 0;
}