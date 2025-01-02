#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    bubbleSort(arr);
    cout << "Sorted Array:";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}