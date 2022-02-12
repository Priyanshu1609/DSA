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

bool isSafe(int node, int m, int v, bool adj[101][101], vector<int> &color, int col)
{
    for (int i = 0; i < v; i++)
    {
        if (i != node and adj[i][node] == 1 and color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool graphColor(int node, int m, int v, bool adj[101][101], vector<int> &color)
{
    if (node == v)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, m, v, adj, color, i))
        {
            color[node] = i;
            if (graphColor(node + 1, m, v, adj, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool adj[101][101], int m, int v)
{
    vector<int> color(v, 0);
    if (graphColor(0, m, v, adj, color))
        return true;
    return false;
}

int main()
{

    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++)
    {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;

    return 0;
}