// Sorting technique using Hashing - Linear Probing

#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class HashTable
{
private:
    int HashFunction(const T& k) const; // Hash function to determine the index for a given key
    int D; // Divisor for hash function (size of the hash table)
    T* ht; // Array to store the hash table elements
    int* empty; // Array to indicate if a position in the hash table is empty
public:
    HashTable(int divisor = 11); // Constructor to initialize the hash table with a given size
    ~HashTable()
    {
        delete[] ht;
        delete[] empty;
    }
    int Search(const T& k, T& e) const; // Function to search for an element in the hash table
    HashTable<T>& Insert(const T& e); // Function to insert an element into the hash table
    void Display(); // Function to display the hash table
    void Delete(T e); // Function to delete an element from the hash table
};

template<class T>
HashTable<T>::HashTable(int divisor)
{
    D = divisor; // Set the divisor
    ht = new T[D]; // Initialize the hash table array
    empty = new int[D]; // Initialize the empty array
    for (int i = 0; i < D; i++)
    {
        empty[i] = 1; // Mark all positions as empty initially
    }
}

template<class T>
int HashTable<T>::HashFunction(const T& k) const
{
    int i = k % D; // Compute the hash index
    int j = i; // Initialize probing index
    do
    {
        if (empty[j] || ht[j] == k) return j; // Return index if position is empty or key is found
        j = (j + 1) % D; // Move to the next index (linear probing)
    } while (j != i);
    return j; // Return the index
}

template<class T>
void HashTable<T>::Delete(T e)
{
    int b = HashFunction(e); // Compute the hash index
    if (!empty[b] && ht[b] == e)
    {
        ht[b] = 0; // Set the position to 0 (indicating deleted)
        empty[b] = 1; // Mark the position as empty
    }
    else
    {
        cout << "\nElement not found"; // Element not found in the hash table
    }
}

template<class T>
int HashTable<T>::Search(const T& k, T& e) const
{
    int b = HashFunction(k); // Compute the hash index
    if (empty[b] || ht[b] != k) return 0; // Return 0 if position is empty or key is not found
    e = ht[b]; // Retrieve the element
    return 1; // Return 1 indicating success
}

template<class T>
HashTable<T>& HashTable<T>::Insert(const T& e)
{
    T k = e; // Key to be inserted
    int b = HashFunction(k); // Compute the hash index
    if (empty[b])
    {
        empty[b] = 0; // Mark the position as not empty
        ht[b] = e; // Insert the element
        return *this; // Return the current hash table object
    }
    if (ht[b] == k)
    {
        cout << "\nBad input"; // Key already exists in the hash table
        return *this;
    }
    cout << "\nNo memory"; // No available position found (hash table is full)
    return *this;
}

template<class T>
void HashTable<T>::Display()
{
    cout << endl;
    for (int i = 0; i < D; i++)
    {
        if (empty[i])
            cout << "0 "; // Print 0 for empty positions
        else
            cout << ht[i] << " "; // Print the element at the position
    }
    cout << endl;
}

int main()
{
    HashTable<int> h(11); // Create a hash table of size 11
    int e;
    e = 80;
    h.Insert(e); // Insert element 80
    e = 40;
    h.Insert(e); // Insert element 40
    e = 65;
    h.Insert(e); // Insert element 65
    cout << "\nAfter inserting 80, 40, 65:";
    h.Display(); // Display the hash table after insertion

    cout << endl;
    h.Delete(40); // Delete element 40
    cout << "\nAfter deleting 40:";
    h.Display(); // Display the hash table after deletion

    cout << endl;
    e = 58;
    h.Insert(e); // Insert element 58
    e = 24;
    h.Insert(e); // Insert element 24
    cout << "\nAfter appending 58, 24:";
    h.Display(); // Display the hash table after insertion

    cout << "\nTrying to delete element 25:";
    h.Delete(25); // Try to delete element 25 (not present)
    h.Display(); // Display the hash table

    e = 2;
    h.Insert(e); // Insert element 2
    e = 13;
    h.Insert(e); // Insert element 13
    e = 46;
    h.Insert(e); // Insert element 46
    e = 16;
    h.Insert(e); // Insert element 16
    e = 7;
    h.Insert(e); // Insert element 7
    e = 21;
    h.Insert(e); // Insert element 21
    h.Insert(10); // Insert element 10
    cout << "\nAfter inserting more values:" << endl;
    h.Display(); // Display the hash table after more insertions

    e = 99;
    cout << "\nTrying to insert 99:";
    h.Insert(e); // Try to insert element 99 (hash table is full)
    h.Display(); // Display the hash table

    return 0;
}

