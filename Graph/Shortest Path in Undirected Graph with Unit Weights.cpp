#include<bits/stdc++.h> 

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
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) 
#define pb push_back 

vi shortestPath(int v, vi adj[], int src){
   
    vi dist(v, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it]= dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

signed main(){
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
    vi ans = shortestPath(V, arr, 0);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}