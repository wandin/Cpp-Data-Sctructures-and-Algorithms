// AVL Class ADT - LL Rotation

#include <iostream>

using namespace std;

// Node Class for AVL Tree
class Node
{
public:
    Node* LChild; // Pointer to left child
    Node* RChild; // Pointer to right child
    int Data; // Node data
    int Height; // Height of the node
};

// AVL Class ADT
class AVL
{
public:
    Node* Root; // Pointer to root node

    
    AVL() { Root = nullptr; } 			// Constructor
    int NodeHeight(Node* p);     		// Function to calculate height of a node
    int BalanceFactor(Node* p);     	// Function to calculate balance factor of a node
    
	Node* LLRotation(Node* p);     		// LL Rotation function
    Node* RRRotation(Node* p);			// RR Rotation function
    Node* LRRotation(Node* p);			// LR Rotation function
	Node* RLRotation(Node* p);			// RL Rotation function

    Node* Insert(Node* p, int key); 	// Function to insert a key into the AVL tree
    void InOrder(Node* p);    			// In-order traversal function
    void InOrder() { InOrder(Root); }   // Wrapper function for in-order traversal
    Node* getRoot() { return Root; }    // Function to get the root node

};

int AVL::NodeHeight(Node* p)
{
    int hLeft, hRight;
    // If the node or its left child exists, calculate height of left subtree
    hLeft = (p && p->LChild) ? p->LChild->Height : 0;
    // If the node or its right child exists, calculate height of right subtree
    hRight = (p && p->RChild) ? p->RChild->Height : 0;

    // Return the maximum height + 1
    return hLeft > hRight ? hLeft + 1 : hRight + 1;
}

int AVL::BalanceFactor(Node* p)
{
    int hLeft, hRight;
    // If the node or its left child exists, calculate height of left subtree
    hLeft = (p && p->LChild) ? p->LChild->Height : 0;
    // If the node or its right child exists, calculate height of right subtree
    hRight = (p && p->RChild) ? p->RChild->Height : 0;

    // Return the balance factor
    return hLeft - hRight;
}

Node* AVL::Insert(Node* p, int key)
{
    Node* t;
    // If the node is nullptr, create a new node with the key and return it
    if(p == nullptr)
    {
        t = new Node;
        t->Data = key;
        t->LChild = nullptr;
        t->RChild = nullptr;
        t->Height = 1;
        return t;
    }
    // If the key is less than the node's data, insert into the left subtree
    if(key < p->Data)
    {
        p->LChild = Insert(p->LChild, key);
    }
    // If the key is greater than the node's data, insert into the right subtree
    else if(key > p->Data)
    {
        p->RChild = Insert(p->RChild, key);
    }

    // Update height of the current node
    p->Height = NodeHeight(p);
    // If the balance factor is 2 and the balance factor of left child is 1, perform LL Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == 1)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p)== -2 && BalanceFactor(p->RChild)== -1) //RR Rotation if matchs the check
    {
    	return RRRotation(p);
	}
	else if(BalanceFactor(p)== 2 && BalanceFactor(p->LChild)== -1)	//LR Rotation
	{
		return LRRotation(p);
	}
	else if(BalanceFactor(p)== -2 && BalanceFactor(p->RChild)==1)	//RL Rotation
	{
		return RLRotation(p);
	}
    // Return the current node
    return p;
}

Node* AVL::LLRotation(Node* p)
{
    // Perform Left-Left Rotation
    Node* pL = p->LChild;
    Node* pLR = pL->RChild;

    pL->RChild = p;
    p->LChild = pLR;

    // Update heights
    p->Height = NodeHeight(p);
    pL->Height = NodeHeight(pL);

    // If the current node is the root, update root
    if(Root == p)
    {
        Root = pL;
    }
    // Return the new root
    return pL;
}

Node* AVL::RRRotation(Node* p)
{
    // Perform Right-Right Rotation
	Node* pRight = p->RChild;
    Node* pRightLeft = pRight->LChild;

    pRight->LChild = p;
    p->RChild = pRightLeft;

    // Update heights
    p->Height = NodeHeight(p);
    pRight->Height = NodeHeight(pRight);

    // If the current node is the root, update root
    if(Root == p)
    {
        Root = pRight;
	}
    // Return the new root
    return pRight;
}

Node* AVL::LRRotation(Node* p)
{
    // Perform Left-Right Rotation
	Node* pLeft = p->LChild;
	Node* pLeftRight = pLeft->RChild;
	
	pLeft->RChild = pLeftRight->LChild;
	p->LChild = pLeftRight->RChild;
	
	pLeftRight->LChild = pLeft;
	pLeftRight->RChild = p;
	
    // Update heights
	pLeft->Height = NodeHeight(pLeft);
	p->Height = NodeHeight(p);
	pLeftRight->Height = NodeHeight(pLeftRight);
	
    // If the current node is the root, update root
	if(Root = p)
	{
		Root = pLeftRight;
	}
    // Return the new root
	return pLeftRight;
}

Node* AVL::RLRotation(Node* p)
{
    // Perform Right-Left Rotation
	Node* pRight = p->RChild;
    Node* pRightLeft = pRight->LChild;

    pRight->LChild = pRightLeft->RChild;
    p->RChild = pRightLeft->LChild;

    pRightLeft->LChild = p;
    pRightLeft->RChild = pRight;

    // Update heights
    pRight->Height = NodeHeight(pRight);
    p->Height = NodeHeight(p);
    pRightLeft->Height = NodeHeight(pRightLeft);
    // If the current node is the root, update root
    if(Root==p)
    {
        Root = pRightLeft;
	}
    // Return the new root
    return pRightLeft;
}

void AVL::InOrder(Node* p)
{
    if(p)
    {
        // In-order traversal recursively
        InOrder(p->LChild);
        cout<<p->Data<<" "; // Print the data of the current node
        InOrder(p->RChild);
    }
}

int main()
{
    AVL tll;
    tll.Root = tll.Insert(tll.Root,30);
    tll.Root = tll.Insert(tll.Root,25);
    tll.Root = tll.Insert(tll.Root,20);
    cout<<"\nLL Rotation...";
    tll.InOrder();
    cout<<endl;
    cout<<"Root = "<<tll.Root->Data;
    
    
    AVL trr;
    trr.Root = trr.Insert(trr.Root,5);
    trr.Root = trr.Insert(trr.Root,10);
    trr.Root = trr.Insert(trr.Root,20);
    cout<<endl;
    cout<<"\nRR Rotation...";
    trr.InOrder();
    cout<<endl;
    cout<<"Root = "<<trr.Root->Data;


    AVL tlr;
    tlr.Root = tlr.Insert(tlr.Root,40);
    tlr.Root = tlr.Insert(tlr.Root,25);
    tlr.Root = tlr.Insert(tlr.Root,30);
    tlr.Root = tlr.Insert(tlr.Root,50);
    tlr.Root = tlr.Insert(tlr.Root,55);
    tlr.Root = tlr.Insert(tlr.Root,20);
    cout<<endl;
    cout<<"\nLR Rotation...";
    tlr.InOrder();
    cout<<endl;
    cout<<"Root = "<<tlr.Root->Data;


    AVL trl;
    trl.Root = trl.Insert(trl.Root,100);
    trl.Root = trl.Insert(trl.Root,200);
    trl.Root = trl.Insert(trl.Root,150);
    trl.Root = trl.Insert(trl.Root,300);
    trl.Root = trl.Insert(trl.Root,175);
    trl.Root = trl.Insert(trl.Root,250);
    cout<<endl;
    cout<<"\nRL Rotation...";
    trl.InOrder();
    cout<<endl;
    cout<<"Root = "<<trl.Root->Data;
    

    return 0;
}
