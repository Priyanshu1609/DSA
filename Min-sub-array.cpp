#include <bits/stdc++.h>

using namespace std;

int minSubArraySizeWithSum(int arr[], int n, int x)
{
    int minLen = n + 1;
    int sum = 0, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            if (end - start < minLen)
                minLen = end - start;

            sum -= arr[start++];
        }
    }

    return minLen;
}

int main()
{

    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;

    int ans = minSubArraySizeWithSum(arr, n, x);
    if (ans != n + 1)
        cout << ans << endl;
    else
        cout << "Not found " << endl;
    return 0;
}