#include <iostream>
using namespace std;

int bi(vector<int> &a, int n, int key)
{
    int start = 0, end = n - 1, mid;
    while (end >= start)
    {
        mid = start - (start - end) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a{1, 2, 3, 4, 8, 12, 12, 12, 12, 12, 12, 12, 12, 13, 15, 45, 67};
    int key;
    cin >> key;
    cout << bi(a, a.size(), key) << '\n';
    return 0;
}