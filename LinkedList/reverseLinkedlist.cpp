#include<iostream> 
#include<vector> 

using namespace std; 

signed main(){
    
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    cout << *num.begin() << endl;
    cout << *(num.end() -1);

    return 0;
}