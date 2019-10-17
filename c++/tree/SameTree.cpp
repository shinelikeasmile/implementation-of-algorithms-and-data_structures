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
//-----------------------------------------------------------------------------------------------------------------
bool SameTree(Node* root1,Node* root2){
	if(root1 == NULL && root2 == NULL){return true;}
	if(root1 == NULL || root2 == NULL){return false;}
	return root1->data == root2->data && SameTree(root1->left,root2->left) && SameTree(root1->right,root2->right);
}
//-----------------------------------------------------------------------------------------------------------------
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
	Node *head1 = NULL;
	head1 = bst->addNode(10,head1);
	head1 = bst->addNode(20,head1);
	head1 = bst->addNode(-10,head1);
	head1 = bst->addNode(15,head1);
	head1 = bst->addNode(0,head1);
	head1 = bst->addNode(21,head1);
	head1 = bst->addNode(-1,head1);
	if(SameTree(head,head1)){cout<<"SAME";}
	else{cout<<"NOT SAME";}	
}
