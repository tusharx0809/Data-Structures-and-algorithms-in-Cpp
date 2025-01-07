#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

float findMax(const vector<float>& arr) {
    float maxVal = arr[0];
    for (float num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Normalize values to the range [0, 1) if not already
    float maxValue = findMax(arr); // Use custom findMax
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] / maxValue) * n; // Scaling to range [0, 1)
        if (bucketIndex == n) bucketIndex--;      // Edge case for max value
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    // Concatenate all buckets into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.76, 0.74, 0.12, 0.15, 1, 1.5, 0.54, 0.42, 0.95, 0.87, 0.85};
    int size = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    bucketSort(arr);

    cout << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
