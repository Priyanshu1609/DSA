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

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void insert(int x)
{
    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }

        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            if (x > pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian()
{
    if (pqmin.size() == pqmax.size())
        return (pqmax.top() + pqmin.top()) / 2.0;

    else if (pqmin.size() > pqmax.size())
        return pqmin.size();

    else
        return pqmax.size();
}

int main()
{
    insert(10);
    cout << findMedian() << endl;
    return 0;
}


