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

class Solution
{
public:
    void check(int i, int j, vector<vector<int>> &m, int n, vector<string> ans, string move, vector<vector<int>> &vis, vector<int> di, vector<int> dj)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int it = 0; it < 4; it++)
        {
            int nexti = i + dir[it];
            int nextj = j + dir[it];
            if (nexti >= 0 and nextj >= 0 and nexti < n and nextj < n and !vis[nexti][nextj] and m[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                check(nexti, nextj, m, n, ans, move + dir[it], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<int> di = {+1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};
        if (m[0][0] == 1)
            check(0, 0, m, n, ans, "", vis, di, dj);

        return ans;
    }
};

signed main()
{

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}