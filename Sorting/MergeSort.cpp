// Sorting Technique - Merge Sort

#include <iostream>
using namespace std;

// Function to merge two halves of array a into array b
template<class T>
void Merge(T& a, T& b, int low, int mid, int high)
{
    int i = low;         // Initial index for the merged subarray
    int h = low;         // Index for the first half of the array
    int j = mid + 1;     // Index for the second half of the array
    
    // Merge the two halves into array b
    while ((h <= mid) && (j <= high))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];  // Place smaller element from first half into b
            h++;
        }
        else
        {
            b[i] = a[j];  // Place smaller element from second half into b
            j++;
        }
        i++;
    }
    
    // If elements are remaining in the first half, copy them to b
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else  // If elements are remaining in the second half, copy them to b
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    
    // Copy elements from b back to a
    for (int k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

// Recursive function to perform merge sort
template<class T>
void MSort(T& a, T& b, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;  // Find the middle index
        
        // Recursively sort the two halves
        MSort(a, b, low, mid);
        MSort(a, b, mid + 1, high);
        
        // Merge the sorted halves
        Merge(a, b, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "\nEnter the size of array: " << endl;
    cin >> n;
    
    int* a = new int[n];  // Dynamic array for storing elements
    int* b = new int[n];  // Temporary array for merging
    
    cout << "\nEnter the " << n << " elements into array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];  // Input elements into array a
    }
    
    cout << "\nElements before sorting are..\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";  // Display elements before sorting
    }
    
    // Sort the array using Merge Sort
    MSort(a, b, 0, n - 1);
    
    cout << "\nElements after sorting are..\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";  // Display elements after sorting
    }
    
    delete[] a;  // Free memory allocated for array a
    delete[] b;  // Free memory allocated for array b
    
    return 0;
}

