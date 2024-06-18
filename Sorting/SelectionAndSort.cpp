// Sorting Technique using Selection Sort

#include <iostream>

using namespace std;

// Template function to print the array
template<class T>
void Print(T& vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Function to swap two integers
void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform Selection Sort on an array
void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)  // Outer loop for traversing each element
    {
        int j, k;
        for (j = k = i; j < n; j++)  // Inner loop to find the minimum element in the unsorted part
        {
            if (A[j] < A[k])
            {
                k = j;  // Update the index of the minimum element
            }
        }
        Swap(&A[i], &A[k]);  // Swap the minimum element with the first element of the unsorted part
    }
}

int main()
{
    // Array to be sorted
    int A[] = {3, 7, 13, 9, 10, 6, 5, 12, 1, 4, 11, 8, 2};
    int n = sizeof(A) / sizeof(A[0]);  // Calculate the number of elements in the array

    // Print the original array
    Print(A, n, "Original array A");
    cout<<endl;
    // Sort the array using Selection Sort
    SelectionSort(A, n);
    
    // Print the sorted array
    Print(A, n, "Sorted array A");
    
    return 0;  // Return 0 to indicate successful execution
}

