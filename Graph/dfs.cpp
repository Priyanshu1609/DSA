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

void dfs(int node, vi graph[], vi &vis, vi &storeDfs)
{
    storeDfs.pb(node);
    vis[node] = 1;

    for (auto &it : graph[node])
    {
        if (!vis[it])
        {
            dfs(it, graph, vis, storeDfs);
        }
    }
}

vi dfsOfGraph(vi graph[], int v)
{
    vi vis(v , 0);
    vi storeDfs;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, graph, vis, storeDfs);
        }
    }
    return storeDfs;
}

signed main()
{
    int V, E;
    cin >> V >> E;

    vi adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi ans = dfsOfGraph(adj, V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}