// sahil_lede
// TIME: 21:08:39 11/12/2022

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long
#define mod 1000000007
// #define mod 998244353
#define vi vector<int>
#define vs vector<string>
#define pi M_PI
#define nl '\n'
#define pb push_back
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define WOW                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// for(auto it = v.begin(); it != v.end(); it++)

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[0])
        {
            cnt1++;
        }
        else
            break;
    }
    if (a[n - 1] == a[0])
    {
        cnt2 = 0;
    }
    else
        for (int i = n - 1; i > -1; i--)
        {
            if ((a[i] == a[n - 1]))
            {
                cnt2++;
            }
            else
                break;
        }
    if (!cnt2)
        cout << n * (n - 1) << nl;
    else
        cout << 2 * (cnt1 * cnt2) << nl;
}

signed main()
{
    WOW;
    int _T;
    cin >> _T;
    while (_T--)
        solve();
    return 0;
}