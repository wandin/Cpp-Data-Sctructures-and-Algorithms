// Binary Tree(Abstract Data Type) using a Queue

#include <iostream>
#include "QueueClass.cpp"

using namespace std;


// Binary Tree Class ADT
class BinaryTree
{
private:
	Node* Root;
public:	
	BinaryTree() {Root = nullptr; }
	~BinaryTree(){}
	
	void CreateTree();
	void PreOrder() { PreOrder(Root); }
	void PreOrder(Node* );
	void PostOrder() { PostOrder(Root); }
	void PostOrder(Node* );
	void InOrder() { InOrder(Root); }
	void InOrder(Node* );
	void LevelOrder(){ LevelOrder(Root); }
	void LevelOrder(Node*);
	int getHeight() { return getHeight(Root); }
	int getHeight(Node* );
	int CountNodes(Node* );
	Node* getRoot(){ return Root; }
};

void BinaryTree::CreateTree()
{
	Node* p;
	Node* t;
	int x;
	
	Queue q(5);
	Root = new Node;
	cout<<"Enter Root Value: "<<flush;
	cin>>x;
	Root->Data = x;
	Root->LChild = nullptr;
	Root->RChild = nullptr;
	q.EnQueue(Root);
	
	while(!q.isEmpty())
	{
		p = q.DeQueue();
		
		cout<<"Enter left child value of "<<p->Data<<": "<<flush;
		cin>>x;
		if(x != -1)
		{
			t = new Node;
			t->Data = x;
			t->LChild = nullptr;
			t->RChild = nullptr;
			p->LChild = t;
			q.EnQueue(t);
		}
		
		cout<<"Enter Right Child value of "<<p->Data<<": "<<flush;
		cin>>x;
		if(x != -1)
		{
			t = new Node;
			t->Data = x;
			t->LChild = nullptr;
			t->RChild = nullptr;
			p->RChild = t;
			q.EnQueue(t);
		}
	}
}

void BinaryTree::PreOrder(Node* p)
{
	if(p)
	{
		cout<<p->Data<<"->"<<flush;
		PreOrder(p->LChild);
		PreOrder(p->RChild);
	}
}

void BinaryTree::InOrder(Node *p)
{
	if(p)
	{
		InOrder(p->LChild);
		cout<<p->Data<<"->"<<flush;
		InOrder(p->RChild);
	}
}

void BinaryTree::PostOrder(Node *p)
{
	if(p)
	{
		PostOrder(p->LChild);
		PostOrder(p->RChild);
		cout<<p->Data<<"->"<<flush;
	}
}

void BinaryTree::LevelOrder(Node *p)
{
	Queue q(100);
	cout<<Root->Data<<"->"<<flush;
	q.EnQueue(Root);
	
	while(!q.isEmpty())
	{
		p = q.DeQueue();
		if(p->LChild)
		{
			cout<<p->LChild->Data<<"->"<<flush;
			q.EnQueue(p->LChild);
		}
		if(p->RChild)
		{
			cout<<p->RChild->Data<<"->"<<flush;
			q.EnQueue(p->RChild);
		}
	}
}

int BinaryTree::CountNodes(Node* p)
{
	if(p == nullptr) return 0;
	
	return CountNodes(p->LChild) + CountNodes(p->RChild) + 1;
}

int BinaryTree::getHeight(Node *p)
{
	int l = 0;
	int r = 0;
	if (p == nullptr) return 0;
	
	l = getHeight(p->LChild);
	r = getHeight(p->RChild);
	if( l > r)
	{
		return l + 1;
	}
	else
		return r + 1;
}

int main()
{
	BinaryTree BT;
	
	BT.CreateTree();
	
	cout<<"Pre Order: "<<flush;
	BT.PreOrder(BT.getRoot());
	cout<<endl;
	
	cout<<"In Order: "<<flush;
	BT.InOrder(BT.getRoot());
	cout<<endl;
	
	cout<<"Post Order: "<<flush;
	BT.PostOrder(BT.getRoot());
	cout<<endl;
	
	cout<<"Level Order: "<<flush;
	BT.LevelOrder(BT.getRoot());
	cout<<endl;
	
	cout<<"Height: "<<BT.getHeight(BT.getRoot())<<endl;
	cout<<"Count: "<<BT.CountNodes(BT.getRoot())<<endl;
	cout<<"Recursive Passing Private Parameter in Constructor"<<endl;
	
	cout << "Pre Order:  " << flush;
    BT.PreOrder();
    cout << endl;

    cout << "In Order:   " << flush;
    BT.InOrder();
    cout << endl;

    cout << "Post Order: " << flush;
    BT.PostOrder();
    cout << endl;

    cout << "Level Order:" << flush;
    BT.LevelOrder();
    cout << endl;

    cout << "Height:    " << BT.getHeight() << endl;
	
	return 0;
}














