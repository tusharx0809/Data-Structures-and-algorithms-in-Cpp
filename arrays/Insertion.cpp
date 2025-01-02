#include <iostream>
#include <vector>
using namespace std;

void insertIntElement(int a[], int n, int x, int pos){
    for(int i=n - 1; i >=pos; i--){
        a[i+1] = a[i];
    }
    a[pos] = x;
}

int main(){
    cout << "Enter array size:";
    int n;
    cin >> n;
    int arr[n];
    cout<<"Enter array elements:";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout<<"Initial array:"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int element;
    cout<< "Enter Element to be inserted:";
    cin >> element;
    int index;

    cout << "Enter position:";
    cin >> index;
    insertIntElement(arr, n, element, index);
    cout<<"Final array after insertion:";
    for(int i=0; i<n+1; i++){
        cout << arr[i] <<" ";
    }
}