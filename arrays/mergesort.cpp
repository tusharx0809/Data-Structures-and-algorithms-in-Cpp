#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp vectors to store the divided arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // Merge temp vectors back into arr[l...r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Print the merged array after each merge step
    cout << "Merged Array: ";
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(vector<int> &arr, int l, int r)
{
    // Print the current subarray before dividing
    cout << "Dividing Array: ";
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    if (l >= r)
    {
        return;
    }

    

    int m = l + (r - l) / 2; // Finding mid index to divide
    mergeSort(arr, l, m);     // Left subarray
    mergeSort(arr, m + 1, r); // Right subarray
    merge(arr, l, m, r);      // Merging the two halves
}

int main()
{
    vector<int> arr = { 6, 5, 4, 3, 2, 1};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
