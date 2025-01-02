#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int element){
    int l=0, r=arr.size()-1;

    while(l <= r){
        int m = l + (r-l) /2;
        if(arr[m] == element){
            return m;
        }else if(arr[m] < element){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {0, 1, 2, 3, 4, 5};
    cout << "Enter element to find:";
    int ele;
    cin >>ele;

    cout<< "Element found at index:"<< binarySearch(arr, ele);
}