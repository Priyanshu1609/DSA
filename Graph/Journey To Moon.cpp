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

void dfs(int node, vi graph[], vi &vis, int &counter)
{
    vis[node] = 1;
    counter++;
    for (auto &it : graph[node])
    {
        if (!vis[it])
        {
            dfs(it, graph, vis, counter);
        }
    }
}

signed main()
{
    int v, e;
    cin >> v >> e;

    vi adj[v];

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(v, 0);
    vi sol;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            int counter = 0;
            dfs(i, adj, vis, counter);
            sol.pb(counter);
        }
    }
    int ans = (v * (v - 1)) / 2;
    for(auto &it : sol){
        int t = (it * (it - 1)) / 2;
        ans -= t;
    }
    cout << ans << endl;

    return 0;
}