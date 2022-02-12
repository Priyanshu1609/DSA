#include <bits/stdc++.h>

using namespace std;

int setBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

bool powerof2(int n)
{
    return (n and !(n & (n - 1)));
}

int numberofOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

void subsets(int arr[], int n)
{

    for (int i = 0; i < (1 << n); i++)
    {
        cout << "{";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j];
            }
        }
        cout << "}";
        cout << endl;
    }
}
int unique(int arr[], int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a ^= arr[i];
    }
    return a;
}

void unique2(int arr[], int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a ^= arr[i];
    }
    int tempxor = a;
    int setbit = 0, pos = 0;
    while (setbit != 1)
    {
        setbit = a & 1;
        pos++;
        a = a >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos - 1))
        {
            newxor ^= arr[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
}

int main()
{
    // int n ; cin>> n;
    // cout << powerof2(n);
    // cout << numberofOnes(n);
    // int arr[4] = {1, 2, 3};
    // subsets(arr, 3);
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique2(arr, 8);

    return 0;
}