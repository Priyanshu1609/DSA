#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    bool found = false;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (lo < hi)
        {
            int curr = a[i] + a[lo] + a[hi];
            if (curr == target)
            {
                found = true;
            }
            if(curr > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
    }
    cout << found << endl;
    return 0;
}