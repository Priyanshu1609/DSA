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

bool helper(int node, vector<int> &color, vector<int> adj[])
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        for (auto it : adj[src])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[src];
                q.push(it);
            }
            else if (color[it] == color[src])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!helper(i, color, adj))
                return false;
        }
    }
    return true;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vi adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cout << isBipartite(n , adj);
    return 0;
}