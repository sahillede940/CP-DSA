#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < n; j++)
        {
            cnt++;
            if (arr[min_i] > arr[j])
                min_i = j;
        }
        swap(arr[i], arr[min_i]);
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << '\n';
    cout << "cout = " << cnt << '\n';

    return 0;
}