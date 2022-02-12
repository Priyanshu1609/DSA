#include<bits/stdc++.h> 

using namespace std; 

int main(){
    string s; cin >>s;
    vector<int> a(256, -1);
    int maxLen=0, start= -1;
    for(int i=0; i< s.size() ; i++){
        if(a[s[i]]> start){
            start = a[s[i]];
        }
        a[s[i]]= i;
        maxLen= max(maxLen, i-start);
    }
    return 0;
}

