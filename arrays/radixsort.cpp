#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {904, 46, 5, 74, 62, 1};
    int size = arr.size();

    cout<<"Original Array: ";
    for(int num: arr){
        cout<< num <<" ";
    }
}