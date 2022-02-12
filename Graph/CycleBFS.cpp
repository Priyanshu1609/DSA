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

bool checkCycle(int s, vi &vis, vi adj[], int v)
{

    queue<pair<int, int>> q;
    q.push({s, -1});
    vis[s] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (prev != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vi adj[], int v)
{
    vi vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, vis, adj, v))
                return true;
        }
    }
    return false;
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

    bool ans = isCycle(adj, V);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}