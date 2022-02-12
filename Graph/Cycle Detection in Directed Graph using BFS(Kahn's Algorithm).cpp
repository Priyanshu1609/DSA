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

bool isCycle(int v, vi adj[])
{
    queue<int> q;
    vi indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto &it : adj[i])
            indegree[it]++;
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (count == v)
        return false;
    return true;
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
    cout << isCycle(V, arr);

    return 0;
}