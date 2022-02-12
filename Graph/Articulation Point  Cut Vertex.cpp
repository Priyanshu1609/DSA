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

void DFS(int node, int parent, vi adj[], int &timer, vi &tim, vi &low, vi &vis, vi &isArticulation)
{
    vis[node] = 1;
    low[node] = vis[node] = timer++;
    int child = 0;
    for (auto &it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            DFS(it, node, adj, timer, tim, low, vis, isArticulation);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tim[node] and parent!=-1)
            {
                isArticulation[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tim[it]);
        }

        if(parent ==-1 && child > 1) isArticulation[node] = 1;
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
    vi tim(V, -1);
    vi low(V, -1);
    vi vis(V, 0);
    vi isArticulation(V, 0);

    int timer = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            DFS(i, -1, adj, timer, tim, low, vis, isArticulation);
        }
    }

    return 0;
}