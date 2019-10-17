#include <iostream>
#include <stack>
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
int Size(Node* root)
{
	if(root==NULL){return 0;}
	return Size(root->left) + Size(root->right) + 1;
}
stack<int> s;
bool RootToLeafSum(Node *root,int sum)
{
	if(root==NULL){return false;}
	if(root->left == NULL && root->right == NULL){
		if(root->data==sum){s.push(root->data);return true;}
		else{return false;}
	}
	if(RootToLeafSum(root->left,sum-root->data)){
		s.push(root->data);
		return true;
	}
	if(RootToLeafSum(root->right,sum-root->data)){
		s.push(root->data);
		return true;
	}
	return false;
}

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
	RootToLeafSum(head,45);
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
