#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> &arr, int element){
    for(int i=0;i<arr.size();i++){
        if(element == arr[i]){
            return i;
        }
    }
    return -1;
}


int main(){
    vector<int> arr = {0, 1, 2, 3, 4, 5};
    cout << "Enter element to find:";
    int ele;
    cin >>ele;

    cout<< "Element found at index:"<< linearSearch(arr, ele);
}