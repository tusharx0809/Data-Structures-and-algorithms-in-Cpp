#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<float> &bucket){
    for(int i=1;i<bucket.size();i++){
        float key = bucket[i];
        int j = i-1;
        while(j>=0 && bucket[j] > key){
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}

void bucketSort(vector<float> &arr, int n){
    //Create n empty buckets
    vector<float> b[n];

    //Put array elements in different buckets
    for(int i=0;i<n;i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    //Sort individual bucket using inserstion sort
    for(int i=0;i<n;i++){
        insertionSort(b[i]);
    }


    //Concatenate all buckets into arr
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0; j<b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    vector<float> arr = {0.76, 0.74, 0.12, 0.15, 0.54, 0.42, 0.95, 0.87, 0.85};
    int size = arr.size();

    cout<<"Original array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    bucketSort(arr, size);
    cout<<endl;
    cout<<"Sorted array:";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}