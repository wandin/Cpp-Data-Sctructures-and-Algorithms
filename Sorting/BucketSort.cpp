// Sorting technique using Bucket Sort

#include <iostream>

using namespace std;

// Node class representing each element in the bucket
class Node
{
public:
    int Value;     // Value of the node
    Node* next;    // Pointer to the next node in the list
};

// Function to get the maximum value in the array
int GetMax(int A[], int n)
{
    int max = -32768; // Initialize to a very small number (16-bit signed integer minimum value)
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i]; // Update max if the current element is greater
        }
    }
    return max;
}

// Function to insert a value into the bucket at the specified index
void Insert(Node** ptrBucket, int index)
{
    Node* temp = new Node; // Create a new node
    temp->Value = index;   // Set the node's value
    temp->next = nullptr;  // Initialize the next pointer to nullptr

    if (ptrBucket[index] == nullptr)
    {
        ptrBucket[index] = temp; // If the bucket is empty, insert the node
    }
    else
    {
        Node* p = ptrBucket[index];
        while (p->next != nullptr)
        {
            p = p->next; // Traverse to the end of the linked list
        }
        p->next = temp; // Insert the node at the end
    }
}

// Function to delete a value from the bucket at the specified index
int Delete(Node** ptrBucket, int index)
{
    Node* p = ptrBucket[index];            // Get the first node in the bucket
    ptrBucket[index] = ptrBucket[index]->next; // Update the bucket to point to the next node
    int x = p->Value;                      // Get the value of the node
    delete p;                              // Delete the node
    return x;                              // Return the value
}

// Function to perform Bucket Sort on the array
void BucketSort(int A[], int n)
{
    int max = GetMax(A, n); // Get the maximum value in the array

    // Create an array of bucket pointers
    Node** buckets = new Node* [max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        buckets[i] = nullptr; // Initialize all buckets to nullptr
    }

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++)
    {
        Insert(buckets, A[i]);
    }

    // Reconstruct the sorted array from the buckets
    int i = 0, j = 0;
    while (i < max + 1)
    {
        while (buckets[i] != nullptr)
        {
            A[j++] = Delete(buckets, i); // Delete elements from buckets and insert them back into the array
        }
        i++;
    }

    // Clean up allocated memory
    delete[] buckets;
}

// Function to display the elements of the array
void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " "; // Print each element followed by a space
    }
}

int main()
{
    int A[] = {23, 18, 38, 55, 89, 10, 0, 1, 4}; // Initialize the array to be sorted
    int size = sizeof(A) / sizeof(A[0]); // Calculate the size of the array

    cout << "\nBefore Sorting..." << endl;
    Display(A, size); // Display the array before sorting

    cout << "\n\nAfter Sorting..." << endl;
    BucketSort(A, size); // Sort the array using Bucket Sort
    Display(A, size); // Display the array after sorting

    return 0; // Return 0 to indicate successful execution
}

