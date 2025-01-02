#include <iostream>
#include <vector>
using namespace std;

int get_min(vector<int> &arr)
{
    int min = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min) // Corrected comparison to use `min` instead of `arr[0]`
        {
            min = arr[i];
        }
    }
    return min;
}

int get_max(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max) // Corrected comparison to use `max` instead of `arr[0]`
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    vector<int> arr = {2,1,2,3,1,2,4};
    int min = get_min(arr);
    cout << "Minimum element: " << min << endl;
    int max = get_max(arr);
    cout << "Maximum element: " << max << endl;

    // Create a frequency array
    vector<int> range(max + 1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        range[arr[i]]++;
    }

    cout << "Range Array: ";
    for (int i = 0; i < range.size(); i++)
    {
        cout << range[i] << " ";
    }
    cout << endl;

    // Build the cumulative frequency array
    for (int i = 1; i < range.size(); i++)
    {
        range[i] += range[i - 1];
    }

    cout << "Cumulative Frequency Array: ";
    for (int i = 0; i < range.size(); i++)
    {
        cout << range[i] << " ";
    }
    cout << endl;

    // Sort the array
    vector<int> sorted_arr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) // Traverse original array in reverse for stability
    {
        int value = arr[i];
        int position = range[value] - 1; // Get position for current value
        sorted_arr[position] = value;   // Place value in the sorted array
        range[value]--;                 // Decrement the frequency
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < sorted_arr.size(); i++)
    {
        cout << sorted_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
