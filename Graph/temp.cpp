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



// function find all prime numbers
void prime (int n) {
    vi prime(n+1, 1);
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            for (int j = i*2; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            cout << i << " ";
        }
    }
    
}










signed main(){
    
    return 0;
}