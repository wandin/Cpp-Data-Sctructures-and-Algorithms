#include <iostream>
#include <cmath>

using namespace std;

// Function to partition the array into positive and negative elements
int partition(int nums[], int n) {
    int pIndex = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            swap(nums[i], nums[pIndex]);
            pIndex++;
        }
    }
    return pIndex;
}

// Function to find the smallest positive missing number
int findSmallestMissing(int nums[], int n) {
    int k = partition(nums, n);
    for (int i = 0; i < k; i++) {
        int val = abs(nums[i]);
        if (val - 1 < k && nums[val - 1] >= 0) {
            nums[val - 1] = -nums[val - 1];
        }
    }
    for (int i = 0; i < k; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return k + 1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    cout << "The smallest positive missing number is " << findSmallestMissing(nums, 6);
    return 0;
}

