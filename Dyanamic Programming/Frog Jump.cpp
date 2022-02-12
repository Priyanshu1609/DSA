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

// frog jump dynamic programming
int frogJumpK(int n, int k) {
    vi dp(n + 1, 0);
    dp[0] = 1;
    forc(i, 1, n) {
        forc(j, 1, k) {
            if (i - j >= 0) dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int f(int ind, vi &heights, vi &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

signed main()
{
    int n = 8;
    vi dp(n + 1, -1);

    return 0;
}