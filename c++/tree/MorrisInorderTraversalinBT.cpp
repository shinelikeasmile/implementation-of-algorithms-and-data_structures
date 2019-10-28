#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
	Node* left;
	Node* right;
	int data;
	
	static Node* newNode(int data)
	{
		Node* n=new Node();
		n->left=NULL;
		n->right=NULL;
		n->data=data;
		return n;
	}
};
queue<Node*>leafnodes;
class BinaryTree{
	public:
	static Node* addNode(Node*root,int data)
	{
		Node* node=Node::newNode(data);
		if(root==NULL)
		{   leafnodes.push(node);
			return node;}
		if(leafnodes.front()->left==NULL)
				{	leafnodes.front()->left=node;
					leafnodes.push(node);
					return root; }
		else{leafnodes.front()->right=node;
					leafnodes.push(node);
					leafnodes.pop();
					return root;}		
		
    }
};
//--------------LevelOrderTraversal----------------------------------
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
//----------MorrisInorderTraversal--------------------------------------
void MorrisInorderTraversal(Node* root)
{
	do{
	if(root->left!=NULL)
	{
		Node* predecessor = root->left;
		while(predecessor->right!=NULL && predecessor->right!=root)
		{ predecessor = predecessor->right;}
		if(predecessor->right == NULL)
		{
			predecessor->right=root;
			root=root->left;
		}
		else
		{
			cout<<predecessor->right->data<<" ";
			root=predecessor->right->right;
		}	
	}
	else
	{
		cout<<root->data<<" ";
		root=root->right;
	}
	}while(root!=NULL);
}
using namespace std;
int main()
{
	BinaryTree *bt = new BinaryTree();
	Node *head=NULL;
	head=bt->addNode(head,25);
	head=bt->addNode(head,18);
	head=bt->addNode(head,50);
	head=bt->addNode(head,19);
	head=bt->addNode(head,20);
	head=bt->addNode(head,35);
	head=bt->addNode(head,60);
	head=bt->addNode(head,25);
	head=bt->addNode(head,15);
	head=bt->addNode(head,18);
	head=bt->addNode(head,25);
	head=bt->addNode(head,20);
	head=bt->addNode(head,40);
	head=bt->addNode(head,55);
	head=bt->addNode(head,70);	
	MorrisInorderTraversal(head);
}
