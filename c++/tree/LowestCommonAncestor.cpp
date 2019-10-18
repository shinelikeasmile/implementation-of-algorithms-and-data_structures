#include <iostream>
#include <queue>
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
//--------------------------------Level order traversal---------------
queue<Node*> q1;
queue<Node*> q2;
void LevelOrderTraversal(Node* root)
{
	if(root==NULL){return;}
	q1.push(root);
	while(q1.size() || q2.size())
	{
		while(q1.size())
		{
			Node *n=q1.front();
			cout<<n->data<<" ";
			q1.pop();
			if(n->left!=NULL){q2.push(n->left);}
			if(n->right!=NULL){q2.push(n->right);}	
		}
		cout<<"\n";
		while(q2.size())
		{
			Node *n=q2.front();
			cout<<n->data<<" ";
			q2.pop();
			if(n->left!=NULL){q1.push(n->left);}
			if(n->right!=NULL){q1.push(n->right);}	
		}
		cout<<"\n";	
	}
}
//----------------Lowest Common Ancestor------------------------------
Node* LCA(Node* root,int key1,int key2)
{
	if(root->data>key1 && root->data>key2){return LCA(root->left,key1,key2);}
	else if(root->data<key1 && root->data<key2){return LCA(root->right,key1,key2);}
	else {return root;}
}
//--------------------------------------------------------------------
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
	cout<<LCA(head,15,20)->data;
}
