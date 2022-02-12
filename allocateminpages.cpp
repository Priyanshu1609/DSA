#include <bits/stdc++.h>

using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    int studentsReq = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (sum + arr[i] > min)
        {
            studentsReq++;
            sum = arr[i];
            if (studentsReq > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocateMin(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0, end = sum;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(mid, ans);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 4;
    int m = 2;
    int arr[] = {12, 34, 67, 90};
    cout << allocateMin(arr, n, m);
    return 0;
}