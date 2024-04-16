// Binary Tree Class using Abstract Data Type
// We are using a Stack to perform the Iterative methods in the Tree.

#include <iostream>
#include "StackClass.cpp"

using namespace std;

template<class T>
class Node
{
public:
	T Data;
	Node<T> *Left;
	Node<T> *Right;
};

template<class T>
class BinaryTree
{
	
public:
	Node<T> *Root;
	BinaryTree() { Root = NULL; }
	
	Node<T> *newNode(T);
	void TraverseInOrder(Node<T> *);
	void TraversePreOrder(Node<T> *);
	void TraversePostOrder(Node<T> *);
	void IterativeInOrder(Node<T> *);
	void IterativePreOrder(Node<T> *);
	int getHeight(Node<T> *);
};

template<class T>
Node<T> * BinaryTree<T>::newNode(T Data)
{
	Root = new Node<T>;
	Root->Data = Data;
	Root->Left = NULL;
	Root->Right = NULL;
	return(Root);
}

template<class T>
void BinaryTree<T>::TraverseInOrder(Node<T> *temp)
{
	if(temp != NULL)
	{
		TraverseInOrder(temp->Left);
		cout<<" "<< temp->Data;
		TraverseInOrder(temp->Right);
	}
}

template<class T>
void BinaryTree<T>::TraversePreOrder(Node<T> *temp)
{
	if(temp != NULL)
	{
		cout<<" "<<temp->Data;
		TraversePreOrder(temp->Left);
		TraversePreOrder(temp->Right);
	}
}

template<class T>
void BinaryTree<T>::TraversePostOrder(Node<T> *temp)
{
	if(temp != NULL)
	{
		TraversePostOrder(temp->Left);
		TraversePostOrder(temp->Right);
		cout<<" "<<temp->Data;
	}
}
template<class T>
void BinaryTree<T>::IterativeInOrder(Node<T> *p)
{
	Stack<Node<T> *> S(10);
	while(p || !S.isEmpty())
	{
		if(p)
		{
			S.Push(p);
			p = p->Left;
		}
		else
		{
			S.Pop(p);
			cout<<p->Data<<" ";
			p = p->Right;
		}
	}
}

template<class T>
void BinaryTree<T>::IterativePreOrder(Node<T> *p)
{
	Stack<Node<T> *> S(10);
	while(p || !S.isEmpty())
	{
		if(p)
		{
			cout<<p->Data<<" ";
			S.Push(p);
			p = p->Left;
		}
		else
		{
			S.Pop(p);
			p = p->Right;
		}
	}
}

template<class T>
int BinaryTree<T>::getHeight(Node<T> *p)
{
	int l = 0;
	int r = 0;
	if(p == NULL) return 0;
	
	l = getHeight(p->Left);
	r = getHeight(p->Right);
	if(l > r)
	{
		return l + 1;
	}
	else
	{
		return r + 1;
	}
}

int main()
{
	BinaryTree<char> BT;
	Node<char> *r = BT.newNode('A');
	r->Left = BT.newNode('B');
	r->Right = BT.newNode('C');
	r->Right->Left = BT.newNode('D');
	r->Left->Right = BT.newNode('E');
	
	// Pre Order recursive and Iterative
	cout<<"\nPreOrder Traversal: ";
	BT.TraversePreOrder(r);
	
	cout<<"\nIterative PreOrder Traversal: ";
	BT.IterativePreOrder(r);
	cout<<"\n----------------------"<<endl;

	// End Of Pre Order recursive and Iterative
	
	
	cout << "\nInorder traversal: ";
  	BT.TraverseInOrder(r);

  	cout <<"\nIterative Inorder traversal: ";
  	BT.IterativeInOrder(r);
	cout<<"\n----------------------"<<endl;


  	cout << "\nPostorder traversal: ";
  	BT.TraversePostOrder(r);
	cout<<"\n----------------------"<<endl;

  	cout<<"\nHeight: "<<BT.getHeight(r);
	
	
	
	return 0;
}








