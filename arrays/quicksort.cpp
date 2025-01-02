#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int> &arr, int l, int h){
    int pivot = arr[h];
    int i = l-1;

    for(int j=l;j<=h-1;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    cout<<i+1<<endl;
    return i+1;
}

void quickSort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main()
{
    vector<int> arr = {8,2,4,7,1,3,9,6,5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}