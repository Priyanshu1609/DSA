#include <bits/stdc++.h>

using namespace std;
bool isFeasible(int arr[], int k, int n, int mid)
{
    int pos = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largminDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int left = 1, right = arr[n - 1];
    int result = -1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(arr, k, n, mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largminDist(arr, n ,k);
    return 0;
}