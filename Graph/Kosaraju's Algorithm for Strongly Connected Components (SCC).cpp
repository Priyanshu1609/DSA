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

void dfs(int node, stack<int> &st, vi adj[], vi &vis)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, adj, vis);
        }
    }
    st.push(node);
}
void revDfs(int node, vi &vis, vi trans[])
{
    vis[node] = 1;
    cout << node << " ";
    for (auto &it : trans[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, trans);
        }
    }
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
    stack<int> st;
    vi vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, adj, vis);
        }
    }

    vi transpose[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto &it : adj[i])
        {
            transpose[it].pb(i);
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}