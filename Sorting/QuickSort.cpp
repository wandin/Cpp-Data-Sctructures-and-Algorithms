#include<iostream>
using namespace std;

// Function to swap two elements of type T using pointers
template<class T>
void swap(T *x, T *y)
{
    T temp;     // Temporary variable to hold the value during swap
    temp = *x;  // Store the value pointed to by x in temp
    *x = *y;    // Assign the value pointed to by y to x
    *y = temp;  // Assign the value stored in temp to y
}

// Function to partition the array A[] based on a pivot element
template<class T>
int Partition(T A[], int low, int high)
{
    T pivot = A[low];   	// Choose the pivot element (first element in this case)
    int i = low, j = high;  // Initialize indices i and j for partitioning
    
    do
    {
        // Move i to the right until you find an element greater than pivot
        do { i++; } while (A[i] <= pivot && i <= high);
        
        // Move j to the left until you find an element less than or equal to pivot
        do { j--; } while (A[j] > pivot && j >= low);
        
        // Swap A[i] and A[j] if i is less than j
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);  // Repeat until i is not less than j
    
    // Move the pivot element to its correct position
    swap(&A[low], &A[j]);
    
    // Return the index of the pivot element after partitioning
    return j;
}

// Function to perform Quick Sort on array A[] from index low to high
template<class T>
void QuickSort(T A[], int low, int high)
{
    if (low < high)
    {
        int j = Partition(A, low, high);    // Partition the array and get the pivot index
        QuickSort(A, low, j);               // Recursively sort elements before the pivot
        QuickSort(A, j + 1, high);          // Recursively sort elements after the pivot
    }
}

// Function to display the elements of array A[] of size n
template<class T>
void Display(T A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " "; 	// Print each element followed by a space
    }
    cout << endl;   			// Move to the next line after printing all elements
}

int main()
{
    int A[] = {32, -15, 115, 12, 15, 89, 785, 113, 1303, 1};   	// Initialize an integer array A
    int n = sizeof(A) / sizeof(A[0]);   						// Calculate the number of elements in array A
    
    cout << "\nBefore Sorting the array..." << endl; 			// Print message indicating original array state
    Display(A, n);  											// Display the elements of array A
    
    QuickSort(A, 0, n); 										// Sort the array A using Quick Sort
    
    cout << "\nAfter Sorting the array..." << endl;  			// Print message indicating sorted array state
    Display(A, n);  											// Display the sorted elements of array A
    
    return 0;   												// Return 0 to indicate successful completion of program
}

