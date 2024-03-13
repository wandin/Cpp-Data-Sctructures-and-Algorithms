#include <iostream>
using namespace std;

// Function to find the minimum number of operations required
// to make the elements of the array a palindrome
int findMin(int arr[], int n)
{
    int count = 0;          // Initialize a counter for operations
    int i = 0, j = n - 1;   // Initialize two pointers i and j
    
    // Loop until the two pointers meet or cross each other
    while (i < j)
    {
        // If the element at position i is smaller than the element at position j
        if (arr[i] < arr[j])
        {
            // Add the element at position i to the next element and move i to the right
            arr[i + 1] += arr[i];
            i++; 
            count++;    // Increment the count of operations
        }
        // If the element at position i is greater than the element at position j
        else if (arr[i] > arr[j])
        {
            // Add the element at position j to the previous element and move j to the left
            arr[j - 1] += arr[j];
            j--; 
            count++;    // Increment the count of operations
        }
        // If both elements are equal
        else {
            // Move both pointers towards each other
            i++; 
            j--;
        }
    }
    return count;   // Return the minimum number of operations required
}

int main()
{
    int arr[] = { 1, 6, 3, 4 };    // Input array
    int n = sizeof(arr) / sizeof(arr[0]);   // Calculate the size of the array
    int min = findMin(arr, n);  // Find the minimum number of operations
    cout << "\nThe minimum number of operations required is " << min << endl;  // Print the result
    return 0;   // Return 0 to indicate successful completion
}

