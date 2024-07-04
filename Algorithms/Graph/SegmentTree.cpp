#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\VSCODE\DEBUG.h"
#endif

#define sahil main
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007 // 998244353
#define YES kout("YES")
#define NO kout("NO")

int n;
const int N = 100;
// storing vals
int A[N];
// storing nodes value basically segment tree
int Tree[4 * N]; //  4 * N for safe side

void build(int node, int start, int end)
{

    if (start == end)
    {
        // leaf node case
        Tree[node] = A[start];
        return;
    }

    int mid = (start + end) / 2;
    int L = 2 * node, R = 2 * node + 1;

    // left child with node no of L
    build(L, start, mid);

    // right child with node no of R
    build(R, mid + 1, end);

    Tree[node] = Tree[L] + Tree[R];
}

void update(int node, int start, int end, int i, int x)
{
    if (start == end)
    {
        // update value in ith posi to x
        A[start] = x;
        Tree[node] = x;
        return;
    }

    int mid = (start + end) / 2;
    int L = 2 * node, R = 2 * node + 1;
    if (i <= mid)
    {
        // if i is less than equal to mid go to left
        update(L, start, mid, i, x);
    }
    else
    {
        // else go right
        update(R, mid + 1, end, i, x);
    }
    Tree[node] = Tree[L] + Tree[R];
}

int print(int node, int start, int end, int l, int r)
{
    if (end < l || start > r)
        return 0; // non intersecting segment

    if (start >= l && end <= r)
        return Tree[node];

    int mid = (start + end) / 2;
    int L = 2 * node, R = 2 * node + 1;

    return print(L, start, mid, l, r) + print(R, mid + 1, end, l, r);
}

signed sahil()
{
    // ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // build the segment tree with root node as 1
    build(1, 0, n - 1);

    // for (int i = 1; i < 4 * n; i++)
    // {
    //     cout << Tree[i] << '\n';
    // }

    // ask for queries
    int qry; // type of query
    while (true)
    {
        cin >> qry;
        if (qry == 0)
            break;
        if (qry == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << print(1, 0, n - 1, l, r) << '\n';
        }
        else
        {
            int i, x;
            cin >> i >> x;
            update(1, 0, n - 1, i, x);
            for (int i = 0; i < n; i++)
            {
                cout << A[i] << ' ';
            }
            cout << "\nupdated\n";
        }
    }

    return 0;
}