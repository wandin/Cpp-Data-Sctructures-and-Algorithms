// Sorting technique using HashingChaining

#include <iostream>
#include <vector>

using namespace std;

// Node structure to represent each key-value pair in the hash table
struct Node
{
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

// HashTable class to implement the hashing with chaining technique
class HashTable
{
private:
    vector<Node*> table; // Vector to store the head nodes of linked lists for each hash index
    int size; // Size of the hash table

    // Hash function to calculate the index for a given key
    int Hash(int key)
    {
        return key % size;
    }

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int sz) : size(sz)
    {
        table.resize(size, nullptr);
    }

    // Destructor to clean up the dynamically allocated memory
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node* current = table[i];
            while (current != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    // Insert a key-value pair into the hash table
    void Insert(int key, int value)
    {
        int index = Hash(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            Node* current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for a key in the hash table and return its value
    int Search(int key)
    {
        int index = Hash(key);
        Node* current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Return -1 if the key is not found
    }

    // Remove a key from the hash table
    void Remove(int key)
    {
        int index = Hash(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

int main() {
    // Create a hash table with size 10
    HashTable ht(10);

    // Insert some key-value pairs
    ht.Insert(10, 100);
    ht.Insert(20, 200);
    ht.Insert(30, 300);

    // Search for a key
    int value = ht.Search(20);
    if (value != -1) {
        cout << "Value found: " << value << endl;
    } else {
        cout << "Value not found" << endl;
    }

    // Remove a key
    ht.Remove(20);

    // Search again after removal
    value = ht.Search(20);
    if (value != -1) {
        cout << "Value found: " << value << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}

