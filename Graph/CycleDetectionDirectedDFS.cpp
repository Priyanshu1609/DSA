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

bool checkCycle(int node, int v, vi adj[], vi &vis, vi &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto &it : adj[node])
    {
        if (checkCycle(it, v, adj, vis, dfsVis))
        {
            return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool isCycle(vi adj[], int v)
{
    vi vis(v + 1, 0);
    vi dfsVis(v + 1, 0);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, v, adj, vis, dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}

signed main()
{
     int V, E;
    cin >> V >> E;
    vi arr[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    cout <<  isCycle(arr ,V );
    

    return 0;
}