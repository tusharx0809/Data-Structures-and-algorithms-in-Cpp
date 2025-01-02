#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << maxSubArraySum(arr) << endl;
    return 0;
}