#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int open_b = 0, close_b = 0, flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (flag == 0)
        {
            if (s[i] == ')')
                close_b++;
        }
        if (s[i] == '(')
        {
            flag = 1;
            open_b++;
        }
        else if (s[i] == ')')
        {
            if (open_b < 1)
                open_b++;
            open_b--;
        }
    }
    cout << close_b + open_b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}