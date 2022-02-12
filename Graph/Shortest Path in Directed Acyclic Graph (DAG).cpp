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

void findTopoSort(int node, stack<int> &st, vector<pii> adj[], vi &vis)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it.ff])
        {
            findTopoSort(it.ff, st, adj, vis);
        }
    }
    st.push(node);
}

vi shortestPath(int v, vector<pii> adj[], int src)
{

    vi vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            findTopoSort(i, st, adj, vis);
        }
    }

    vi dist(v, INT_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto &it : adj[node])
            {
                if (dist[node] + dist[it.ss] < dist[it.ff])
                {
                    dist[it.ff] = dist[node] + dist[it.ss];
                }
            }
        }
    }
    return dist;
}

signed main()
{
    int V, E;
    cin >> V >> E;
    vector<pii> arr[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].pb({v, w});
    }
    vi ans = shortestPath(V, arr, 0);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}