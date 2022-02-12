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

vi shortestPath(int v, vector<pii> adj[], int src)
{
    vi dist(v, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        for (auto &it : adj[node.ss])
        {
            if (dist[node.ss] + it.ss < dist[it.ff])
            {
                dist[it.ff] = dist[node.ss]+ it.ss;
                pq.push({dist[it.ff], it.ff});
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
        arr[v].pb({u, w});
    }
    vi ans = shortestPath(V, arr, 1);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}