#include <bits/stdc++.h>

using namespace std;

#define int long long
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

void solve()
{
    string s;
    cin >> s;
    map<int, int> m;
    priority_queue<pair<int, int>> pq;
    for (char &i : s)
        m[i]++;
    for (auto &i : m)
        pq.push({i.ss, i.ff});
    string ans;

    while (!pq.empty())
    {
        pair<int, int> top1, top2;
        top1 = pq.top();
        pq.pop();
        ans += top1.ss;

        if (!pq.empty())
        {
            top2 = pq.top();
            pq.pop();
            ans += top2.ss;
            if (top2.ff > 1)
                pq.push({top2.ff - 1, top2.ss});
        }

        if (top1.ff > 1)
            pq.push({top1.ff- 1, top1.ss});
    }
    for (int i = 1; i < ans.length(); i++)
    {
        if (ans[i] == ans[i - 1])
        {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    };
    return 0;
}