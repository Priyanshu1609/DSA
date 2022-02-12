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

vi parent(100000);
vi Rank(100000);

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}
int findPar(int u){
    if(parent[u]==u) return u;

    return parent[u] = findPar(u); //Path optimization
}

void Union(int u , int v ){
    u = findPar(u);
    v = findPar(v);

    if(Rank[u] < Rank[v]){
        parent[u] = v;
    }
    else if(Rank[v] < Rank[u]){
        parent[v] = u;
    }
    else{
        parent[v]= u;
        Rank[u]++;
    }

}
//* time complexcity per operation is O(4) == O(1)

signed main()
{
    int n ; cin >> n;
    makeSet(n);
    while(n--) {
        int u , v;
        Union(u, v);
    }
    return 0;
}