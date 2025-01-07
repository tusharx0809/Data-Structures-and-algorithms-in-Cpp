#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<float> arr = {0.76, 0.74, 0.12, 0.15, 0.54, 0.42, 0.95, 0.87, 0.85};
    int size = arr.size();
    cout<<"Original array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    vector<vector<float>> b(size);
    cout<<endl;
    //Put array elements in different buckets
    for(int i=0;i<size;i++){
        int bi = size * arr[i];
        cout << bi <<" ";
    }
    
}