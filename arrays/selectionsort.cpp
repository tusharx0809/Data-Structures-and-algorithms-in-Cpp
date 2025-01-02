#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    vector<int> arr = {6,5,4,3,2,1};
    selectionSort(arr);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}