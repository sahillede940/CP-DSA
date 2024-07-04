// TIME: 02:01:07 19/05/2023

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            //////////  1. N shops and we have to find total combos we can pusrchase of pen ans pencil  ///////////////
            //////////  2. each shops has some discount amount di only if both pen and paper is pusrcahses  ///////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int a[10010], b[10010], d[10010], k, n;

int dp[51][51][51][51];

int max_combos(int shop, int money_left, int pen, int paper)
{
    // pruning
    if (money_left < 0)
        return 0;

    // base conditions
    if (shop == n)
        return min(pen, paper);

    // cache check
    if (dp[shop][money_left][pen][paper] != -1)
        return dp[shop][money_left][pen][paper];

    // transitions
    int ans = 0;
    ans = max(ans, max_combos(shop + 1, money_left, pen, paper));
    ans = max(ans, max_combos(shop + 1, money_left - a[shop], pen + 1, paper));
    ans = max(ans, max_combos(shop + 1, money_left - b[shop], pen, paper + 1));
    ans = max(ans, max_combos(shop + 1, money_left - a[shop] - b[shop] + d[shop], pen + 1, paper + 1));

    return dp[shop][money_left][pen][paper] = ans;
}

signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> d[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << max_combos(0, k, 0, 0) << '\n';

    return 0;
}