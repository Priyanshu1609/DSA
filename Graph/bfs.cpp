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
#define for0(i, v) for (int i = 0; i < (int)(v); ++i)
#define for1(i, v) for (int i = 1; i <= (int)(v); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, v) for (int i = (int)(v)-1; i >= 0; --i)
#define forr1(i, v) for (int i = (int)(v); i >= 1; --i)
#define pb push_back

vi bfsOfGraph(int V, vi arr[])
{
    vi bfs;
    vi vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.pb(node);

                for (auto &it : arr[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
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
    vi ans = bfsOfGraph(V, arr);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}