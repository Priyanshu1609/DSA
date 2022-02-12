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

vi minSpanTree(int v, vector<pii> adj[])
{
    vi key(v, INT_MAX);
    vi parent(v, -1);
    vector<bool> mstSet(v, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    for (int count = 0; count < v - 1; count++)
    {
        int u = pq.top().ss;
        pq.pop();

        mstSet[u] = true;
        for (auto &it : adj[u])
        {
            if (key[it.ff] > it.ss and mstSet[it.ff] == false)
            {
                pq.push({key[it.ff], it.ff});
                key[it.ff] = it.ss;
                parent[it.ff] = u;
            }
        }
    }
    return parent;
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
    vi ans = minSpanTree(V, arr);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}