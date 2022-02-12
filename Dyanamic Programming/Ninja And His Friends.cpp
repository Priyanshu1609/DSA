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

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    for (int dx = -1; dx <= +1; dx++)
    {
        for (int dy = -1; dy <= +1; dy++)
        {
            if (j1 == j2)
                maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dx, j2 + dy, r, c, grid, dp));
            else
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dx, j2 + dy, r, c, grid, dp));
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, r, c, grid, dp);
}
int maximumChocolatesTab(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dx = -1; dx <= +1; dx++)
                {
                    for (int dy = -1; dy <= +1; dy++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dx >= 0 and j1 + dx < c and j2 + dy >= 0 and j2 + dy < c)
                            value += dp[i + 1][j1 + dx][j2 + dy];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
}

signed main()
{
    int r, int c;
    cin >> r >> c;
    vector<vector<int>>grid(r, vector<int>(c));
    for0(i, r)
    {
        for0(j, c)
        {
            cin >> grid[i][j];
        }
    }
    cout << maximumChocolates(r, c, grid) << endl;

    return 0;
}