#include <iostream>
using namespace std;
class Node{
	public:
	Node *left;
	Node *right;
	int data;
	static Node* newNode(int data)
	{
		Node *n =new Node();
		n->left = NULL;
		n->right = NULL;
		n->data = data;
		return n;
	}
};
class BinarySearchTree{
	public:
	Node* addNode(int data ,Node* head){
		Node *tempHead = head;
		Node* n = Node::newNode(data);
		if( head == NULL ) 
		{
			head = n;
			return head;
		}
		Node* prev  = NULL;
		while(head != NULL){
			prev = head;
			if(head->data < data){ head = head->right;}
			else { head = head->left;}
		}
		if(prev->data<data){prev->right = n;}
		else{prev->left=n;}
		return tempHead;
	}
	public:
	int height(Node* root)
	{
		if(root==NULL){return 0;}
		int Lheight = height(root->left);
		int Rheight = height(root->right);
		return std::max(Lheight,Rheight)+1;
	}	
};
class BSTsearch{
	public:
	static Node* Search(Node* root,int key)
	{
		if(root == NULL){ return NULL;}
		if(root->data == key){return root;}
		else if(root->data<key){return Search(root->right,key);}
		else { return Search(root->left,key);}
	}
};
int main()
{
	BinarySearchTree *bst = new BinarySearchTree();
	Node *head = NULL;
	head = bst->addNode(10,head);
	head = bst->addNode(20,head);
	head = bst->addNode(-10,head);
	head = bst->addNode(15,head);
	head = bst->addNode(0,head);
	head = bst->addNode(21,head);
	head = bst->addNode(-1,head);
	//cout<<bst->height(head);
	Node* result = BSTsearch::Search(head,1);
	if(result!=NULL){cout<<result->data;}
	else{cout<<"Not found";}
	
}
