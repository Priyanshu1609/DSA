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

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> in(n+1);
    for (auto &it : trust) {
        in[it[0]]--;
        in[it[1]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(in[i]==n-1) return i;
    }
    return -1;
}

signed main()
{
    // findJudge
    int n = 2;
    vector<vector<int>> trust1 = {{1, 2}};
    cout << findJudge(n, trust1);

    return 0;
}