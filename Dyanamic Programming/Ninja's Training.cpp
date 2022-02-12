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

int solve(int ind, int skip, vector<vector<int>> &dp, vector<vector<int>> &points)
{
    if (ind == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != skip)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[ind][skip] != -1)
        return dp[ind][skip];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != skip)
        {
            int point = points[ind][i] + solve(ind - 1, i, dp, points);
            maxi = max(maxi, point);
        }
    }
    return dp[ind][skip] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int skip = 3;
    return solve(n - 1, skip, dp, points);
}

int ninjaTrainingTab(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int ninjaTrainingSpace(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[0] = max(points[0][1], points[0][2]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + dp[i];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

signed main()
{
    // ninja's training
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << ninjaTraining(n, points) << endl;
    cout << ninjaTrainingTab(n, points);

    return 0;
}