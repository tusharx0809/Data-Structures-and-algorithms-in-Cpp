#include<iostream>
#include<vector>
using namespace std;

int get_max(vector<int> &arr, int size){
    int max = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countingSort(vector<int> &arr, int size, int div){
    vector<int> output(size);
    vector<int> count(10,0);

    for(int i=0;i<size;i++){
        count[(arr[i]/div)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=size-1;i>=0;i--){
        output[count[(arr[i]/div)%10]-1] = arr[i];
        count[(arr[i]/div)%10]--;
    }
    for(int i=0;i<size;i++){
        arr[i] = output[i];
    }
}
void radixSort(vector<int> &arr, int size){
    int max = get_max(arr, size);
    for(int div=1;max/div > 0;div*=10){
        countingSort(arr, size, div);
    }
}
int main(){
    vector<int> arr = {904, 46, 5, 74, 62, 1, 8};
    int size = arr.size();

    cout<<"Original Array: ";
    for(int num: arr){
        cout<< num <<" ";
    }

    cout<<endl;
    radixSort(arr, size);
    
    cout<<"Sorted array: ";
    for(int num: arr){
        cout<<num<<" ";
    }
}