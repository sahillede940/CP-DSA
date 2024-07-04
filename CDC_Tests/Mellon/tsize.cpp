#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sumOfSelectedEmployees(vector<int> scores, int k, int teamSize)
{
    int n = scores.size();
    int sum = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < min(k, n); i++)
        pq.push({scores[i], -i});
    for (int i = max(0, n - k); i < n; i++)
        pq.push({scores[i], -i});
    vector<bool> removed(n);
    while (teamSize > 0 && !pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        if (removed[-p.second])
            continue;
        sum += p.first;
        removed[-p.second] = true;
        teamSize--;
        if (-p.second >= k && -p.second < n - k)
        {
            if (!removed[-p.second - k])
                pq.push({scores[-p.second - k], p.second - k});
            if (!removed[-p.second + k])
                pq.push({scores[-p.second + k], p.second + k});
        }
    }
    return sum;
}

int main()
{
    vector<int> scores = {10, 20, 10, 15, 5, 30, 20};
    int k = 3;
    int teamSize = 2;
    cout << sumOfSelectedEmployees(scores, k, teamSize) << endl; // 50
    return 0;
}
