#include<bits/stdc++.h> 

using namespace std; 

int peakElement(int arr[] , int n, int low , int high){
    int mid = low + (high - low)/2;
    if((mid == 0 or arr[mid] >= arr[mid-1]) and (arr[mid] >= arr[mid +1] or mid == n-1)){
        return mid;
    }

    else if(mid > 0 and arr[mid -1 ] > arr[mid]){
        return peakElement(arr, n, low, mid-1);
    }
    else {
        return peakElement(arr, n, mid +1,high);
    }
}

int main(){
    int arr[]= {0 ,6,8,5,7,9};
    int n = 6;
    cout << peakElement(arr, n, 0, n-1);
    return 0;
}