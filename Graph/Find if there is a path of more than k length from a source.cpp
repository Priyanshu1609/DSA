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

bool helper(int node, int k, vector<pii> adj[], vi &dist)
{
    if (k <= 0)
        return true;

    for (auto &it : adj[node])
    {

        if (dist[it.ff] == 1)
            continue;

        if (it.ss >= k)
            return true;

        dist[it.ff] = 1;

        helper(it.ff, k - it.ss, adj, dist);

        dist[it.ff] = 0;
    }
}

bool pathMoreThanK(int src, int k, vector<pii> adj[], int n)
{
    vi dist(n, 0);
    dist[src] = 1;
    return (helper(src, k, adj, dist));
}

signed main()
{
    int V, E;
    cin >> V >> E;

    vector<pii> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src = 0;
    int k = 60;
    pathMoreThanK(src, k, adj, V) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}