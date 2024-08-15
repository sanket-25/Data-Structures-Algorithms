#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index of the target element
        }

        if (arr[mid] < target) {
            left = mid + 1; // Ignore the left half
        } else {
            right = mid - 1; // Ignore the right half
        }
    }

    return -1; // Return -1 if the target element is not found
}

int main() {
    vector<int> arr = {11, 15, 23, 45, 70}; // Sorted array
    int target = 45;
    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
