#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ld long double
#define ff first
#define ss second
#define vs vector<string>
#define vpll vector<pll>
#define vb vector<bool>
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back

int solve(int ind, vi &arr, vi &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    dp[ind] = max(dp[ind], dp[ind - 1] + arr[ind]);

    return dp[ind];
}

int solveSpace( vi &arr)
{
    int n = arr.size();
    int prev = arr[0], prev2 = 0;

    for (int i = 1; i <= n; i++)
    {
        int take = arr[i];
        if (n > 1)
            take += prev2;
        int skip = 0 + prev;

        int curri = max(take, skip);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

signed main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vi dp(n + 1, -1);
    cout << solve(n, arr, dp);
    return 0;
}