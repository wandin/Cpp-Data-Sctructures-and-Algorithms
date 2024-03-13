#include <iostream>
using namespace std;

// Function to print all subarrays with sum equal to 0
void printAllSubarrays(int nums[], int n)
{
    // Iterate through each element of the array
    for (int i = 0; i < n; i++)
    {
        int sum = 0;    // Initialize sum for current subarray
        // Iterate through subarrays starting from index i
        for (int j = i; j < n; j++)
        {
            sum += nums[j];     // Add current element to sum
            // If sum equals 0, print the subarray
            if (sum == 0)
			{
                cout << "Sub-Array indexes [" << i <<" to " << j << "]\n"; // print the indexes that when summed returns 0
                cout << "[";
				for (int k = i; k <= j; ++k) {				// in this loop here we print the values of each index for easier comprehension
				    cout << nums[k];
				    if (k < j) {
				        cout << ", ";
				    }
				}
				cout << "]\n";
            }
        }
    }
}

int main()
{
    int nums[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };   // Input array
    int n = sizeof(nums)/sizeof(nums[0]);   // Calculate the size of the array
    printAllSubarrays(nums, n);     // Call function to print subarrays with sum equal to 0
    return 0;   // Return 0 to indicate successful completion
}

