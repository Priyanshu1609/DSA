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

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>>& mp, vector<map<int, int>> &row, vector<map<int, int>> &col)
{
    if (r == 9)
    {
        for (auto &it : a)
        {
            for (auto &i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    if (c == 9)
    {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] == '.')
    {
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        int rw = 1 / 3, cl = c / 3;
        if (!mp[{rw, cl}][i] and !row[r][i] and !col[c][i])
        {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c]= i+'0';
            helper(r, c+1,a,  mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c]= '.';
        }
    }
}

void solve(vector<vector<char>> &a)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    for0(i, 9)
    {
        for0(j, 9)
        {
            if (a[i][j] != '.')
            {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;
                row[i][j] = 1;
                col[i][j] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

signed main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'5', '3', '.', '4', '1', '9', '.', '.', '5'},
        {'5', '3', '.', '.', '8', '.', '.', '7', '9'},
    };
    solve(sudoku);
    return 0;
}