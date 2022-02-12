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

// N-th Tribonacci Number recursion
int tribonacci(int n, vi &dp)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];
        
    return dp[n] = tribonacci(n - 1, dp) + tribonacci(n - 2, dp) + tribonacci(n - 3, dp);
}

signed main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << tribonacci(n, dp) << endl;

    return 0;
}