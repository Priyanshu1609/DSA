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

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<node> arr;
    for (int i = 0; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        arr.push_back(node(u, v, wt));
    }

    vi dist(n, INT_MAX);

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &it : arr)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &it : arr)
        {
            if (dist[it.u] == INT_MAX)
                continue;
            if (dist[it.u] + it.wt < dist[it.v])
            {
                cout << "Negative Cycle";
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        for0(i, n)
        {
            cout << i << " " << dist[i];
        }
        cout << endl;
    }

    return 0;
}