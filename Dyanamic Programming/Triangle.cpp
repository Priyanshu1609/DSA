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
int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int dia = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);
    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);

    return dp[i][j] = min(down, dia);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, n, dp);
}


int minimumPathSumTab(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n-1][j] = triangle[n-1][j]; 
    }
    

    for (int i = n-2; i >=0; i--)
    {
        for (int j = i; j >=0 ; j--)
        {
            int dia = triangle[i][j] +dp[i+1][j+1];
            int down = triangle[i][j] + dp[i+1][j];

            dp[i][j] = min(down, dia);
        }
    }
    return dp[0][0];
}


int minimumPathSumSpace(vector<vector<int>> &triangle, int n)
{
    vector<int> next(n, 0);

    for (int j = 0; j < n; j++)
    {
        next[j] = triangle[n-1][j]; 
    }
    

    for (int i = n-2; i >=0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >=0 ; j--)
        {
            int dia = triangle[i][j] +next[j+1];
            int down = triangle[i][j] + next[j];

            curr[j] = min(down, dia);
        }
        next = curr;
    }
    return next[0];
}
signed main()
{
    // triangle dynaamic programming
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> triangle[i][j];
        }
    }
    cout << minimumPathSum(triangle, n) << endl;
    cout << minimumPathSumTab(triangle, n) << endl;
    cout << minimumPathSumSpace(triangle, n) << endl;

    return 0;
}