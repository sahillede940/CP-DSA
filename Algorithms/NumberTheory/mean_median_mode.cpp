// TIME: 19:23:04 09/05/2023

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007
// #define mod 998244353
#define vi vector<int>
#define pi M_PI
#define nl '\n'
#define pb push_back
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define all(o) (o).begin(), (o).end()
#define fo(ji, j) for (auto &ji : j)
#define WOW                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct mmm_dashboard
{
    // mean
    int sum = 0;
    double cnt = 0;

    // variance
    int sum_sq = 0;

    // median
    multiset<int> low, high;

    // mode
    map<int, int> freq;                  // -> number and freq
    multiset<pair<int, int>> freq_order; // -> high freq at end and number

    void balancer()
    {
        if (low.size() < high.size())
        {
            int x = *high.begin();
            high.erase(high.begin());
            low.insert(x);
        }
        if (low.size() > (high.size() + 1))
        {
            int x = *low.begin();
            low.erase(low.begin());
            high.insert(x);
        }
    }

    void insert(int x)
    {

        // mean and variance
        cnt++;
        sum += x;
        sum_sq += x * x;
        // mode
        if (freq_order.find({freq[x], x}) != freq_order.end())
        {
            freq_order.erase(freq_order.find({freq[x], x}));
        }
        freq[x]++;
        freq_order.insert({freq[x], x});

        // median
        if (low.empty())
        {
            low.insert(x);
        }
        else if (x <= *low.rbegin())
        {
            low.insert(x);
        }
        else
        {
            high.insert(x);
        }
        balancer();
    }
    void remove(int x)
    {
        cnt--;
        sum -= x;
        sum_sq -= x * x;
        // mode
        if (freq_order.find({freq[x], x}) != freq_order.end())
        {
            freq_order.erase(freq_order.find({freq[x], x}));
        }
        freq[x]--;
        freq_order.insert({freq[x], x});
    }
    double mean()
    {
        return sum / cnt;
    }
    double variance()
    {
        return sum_sq / cnt - mean() * mean();
    }
    double median()
    {
        if ((int)cnt & 1)
        {
            return *low.rbegin();
        }
        else
        {
            return (*low.rbegin() + *high.begin()) / 2.0;
        }
    }
    double mode()
    {
        return freq_order.rbegin()->second;
    }
};

void solve()
{
    mmm_dashboard db;
    db.insert(1);
    db.insert(2);
    db.insert(4);
    db.insert(4);
    db.insert(4);
    db.insert(4);
    db.remove(1);
    db.insert(3);
    db.remove(3);
    cout << "mean: " << db.mean() << nl;
    cout << "variance: " << db.variance() << nl;
    cout << "median: " << db.median() << nl;
    cout << "mode: " << db.mode() << nl;
}

signed main()
{
    WOW;
    // int _T = 1;
    // cin >> _T;
    // while (_T--)
    solve();
    return 0;
}