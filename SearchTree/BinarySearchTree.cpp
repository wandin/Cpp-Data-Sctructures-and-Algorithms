//Binary Search Tree - Search(), Insert() and Delete() -> Dictionary

#include <iostream>

using namespace std;

class Node
{
public:
    int Data; // Node data
    Node* Left; // Pointer to left child
    Node* Right; // Pointer to right child
};

class BinarySearchTree
{
private:
    Node* Root; // Pointer to root node

public:
    BinarySearchTree() { Root = nullptr; } // Constructor, initializes Root to nullptr
    Node* GetRootElement() { return Root; } // Getter for Root element
    void Insert(int key); // Function to insert a key into the tree
    void InOrder(Node* p); // Function to perform in-order traversal
    Node* Search(int key); // Function to search for a key in the tree
    Node* Delete(Node* p, int key); // Function to delete a key from the tree
    Node* InOrderPred(Node* p); // Function to find the in-order predecessor of a node
    Node* InOrderSucc(Node* p); // Function to find the in-order successor of a node
    int getHeight(Node* p); // Function to get the height of the tree
};

void BinarySearchTree::Insert(int key)
{
    Node* t = Root; // Temporary pointer to traverse the tree
    Node* p; // Pointer to the new node to be inserted
    Node* r; // Pointer to the parent node

    if (Root == NULL) // If the tree is empty
    {
        p = new Node; // Create a new node
        p->Data = key; // Set its data
        p->Left = NULL; // Set its left child to nullptr
        p->Right = NULL; // Set its right child to nullptr
        Root = p; // Make it the root of the tree
        return;
    }

    while(t != NULL) // Traverse the tree until a suitable position for insertion is found
    {
        r = t; // Store the parent node
        if (key < t->Data) // If the key is less than the current node's data
            t = t->Left; // Move to the left child
        else if (key > t->Data) // If the key is greater than the current node's data
            t = t->Right; // Move to the right child
        else
            return; // If the key already exists in the tree, return
    }

    p = new Node; // Create a new node
    p->Data = key; // Set its data
    p->Left = NULL; // Set its left child to nullptr
    p->Right = NULL; // Set its right child to nullptr

    if (key < r->Data) // If the key is less than the parent node's data
        r->Left = p; // Insert it as the left child
    else
        r->Right = p; // Insert it as the right child
}

void BinarySearchTree::InOrder(Node* p)
{
    if(p != nullptr) // If the current node is not nullptr
    {
        InOrder(p->Left); // Traverse the left subtree recursively
        cout<<p->Data<<", "<<flush; // Print the data of the current node
        InOrder(p->Right); // Traverse the right subtree recursively
    }
}

Node* BinarySearchTree::Search(int key)
{
    Node* t = Root; // Temporary pointer to traverse the tree
    while(t != nullptr) // Traverse the tree until a suitable position for insertion is found
    {
        if(key == t->Data) // If the key is equal to the current node's data
        {
            return t; // Return the node
        }
        else if(key < t->Data) // If the key is less than the current node's data
        {
            t = t->Left; // Move to the left child
        }
        t = t->Right; // Move to the right child
    }
    return nullptr; // If the key is not found, return nullptr
}

Node* BinarySearchTree::Delete(Node* p, int key)
{
    Node* q;

    if(p == nullptr) // If the node is nullptr
    {
        return nullptr; // Return nullptr
    }

    if(p->Left == nullptr && p->Right == nullptr && p->Data == key) // If the node is a leaf node and its data matches the key
    {
        if(p == Root) // If it's the root node
        {
            Root = nullptr; // Set the root to nullptr
        }
        delete p; // Delete the node
        return nullptr; // Return nullptr
    }

    if(key < p->Data) // If the key is less than the current node's data
    {
        p->Left = Delete(p->Left, key); // Recursively delete from the left subtree
    }
    else if(key > p->Data) // If the key is greater than the current node's data
    {
        p->Right = Delete(p->Right, key); // Recursively delete from the right subtree
    }
    else // If the key is found
    {
        if(getHeight(p->Left) > getHeight(p->Right)) // If the left subtree has greater height
        {
            q = InOrderPred(p->Left); // Find the in-order predecessor
            p->Data = q->Data; // Replace the current node's data with the predecessor's data
            p->Left = Delete(p->Left, q->Data); // Recursively delete the predecessor node
        }
        else // If the right subtree has greater or equal height
        {
            q = InOrderSucc(p->Right); // Find the in-order successor
            p->Data = q->Data; // Replace the current node's data with the successor's data
            p->Right = Delete(p->Right, q->Data); // Recursively delete the successor node
        }
    }
    return p; // Return the modified node
}

Node* BinarySearchTree::InOrderPred(Node* p)
{
    while(p && p->Right != nullptr) // Traverse to the rightmost node
    {
        p = p->Right; // Move to the right child
    }
    return p; // Return the rightmost node
}

Node* BinarySearchTree::InOrderSucc(Node* p)
{
    while(p && p->Left != nullptr) // Traverse to the leftmost node
    {
        p = p->Left; // Move to the left child
    }
    return p; // Return the leftmost node
}

int BinarySearchTree::getHeight(Node* p)
{
    int l, r; // Variables to store heights of left and right subtrees
    if(p == nullptr) return 0; // If the node is nullptr, height is 0

    l = getHeight(p->Left); // Get height of left subtree recursively
    r = getHeight(p->Right); // Get height of right subtree recursively
    if(l > r) // Return the maximum of the heights of left and right subtrees
        return l + 1; // Return left subtree height + 1
    else
        return r + 1; // Return right subtree height + 1
}

int main()
{
    BinarySearchTree BST; // Create an instance of BinarySearchTree

    BST.Insert(10); // Insert elements into the tree
    BST.Insert(20);
    BST.Insert(30);
    BST.Insert(40);
    BST.Insert(50);
    BST.Insert(60);

    BST.InOrder(BST.GetRootElement()); // Perform in-order traversal and print the elements
    cout << endl;

    BST.Delete(BST.GetRootElement(), 30); // Delete an element from the tree
    BST.InOrder(BST.GetRootElement()); // Perform in-order traversal and print the elements

    Node* temp = BST.Search(40); // Search for an element in the tree
    if(temp != nullptr) // If the element is found
        cout << "\n\nElement found: " << temp->Data << endl;
    else
        cout << "\nElement not found" << endl;

    cout << "\nThe Height of tree is: " << BST.getHeight(BST.GetRootElement()); // Print the height of the tree

    return 0; // Exit the program
}

