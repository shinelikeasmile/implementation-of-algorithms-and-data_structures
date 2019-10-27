#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
	Node* left;
	Node* right;
	int data;
	// variables to be used to find out largest BST in binary tree.
	bool isBST;
	int size;
	int min;
	int max;
	
	static Node* newNode(int data)
	{
		Node* n=new Node();
		n->left=NULL;
		n->right=NULL;
		n->data=data;
		n->isBST = true;
		n->size=1;
		n->min=data;
		n->max=data;
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
//--------------PostOrderTraversal-----------------------------------
Node* PostOrderTraversal(Node* root)
{
	if(root==NULL) return NULL;
	if(root->left==NULL && root->right==NULL) {return root;}
	Node* LeftTree = PostOrderTraversal(root->left);
	Node* RightTree = PostOrderTraversal(root->right);
	if(LeftTree!=NULL && RightTree!=NULL)
	{
		if(LeftTree->isBST && RightTree->isBST)
		{ 
			if(root->data > LeftTree->data && root->data <= RightTree->data)
				{root->isBST=true; 
				 root->size = LeftTree->size+RightTree->size+1;
				 root->min=LeftTree->min;
				 root->max=RightTree->max;
				 }
		    else {
				root->isBST=false;
			    root->size=std::max(LeftTree->size,RightTree->size);
			    root->min=LeftTree->min;
			    root->max=RightTree->max;
			    }
		}
		else {
			  root->isBST=false;
			  root->size=std::max(LeftTree->size,RightTree->size);
			  root->min=LeftTree->min;
			  root->max=RightTree->max;
			 }	
		}
	     return root;
	    if(LeftTree==NULL)
	    {
			root->isBST=RightTree->isBST;
			root->size=RightTree->isBST;
			root->min=root->data;
			root->max=RightTree->max;
		}
		else
		{
			root->isBST=LeftTree->isBST;
			root->size=LeftTree->isBST;
			root->min=LeftTree->data;
			root->max=root->data;
			
		}
		return root;
}
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
	//LevelOrderTraversal(head);
	head=PostOrderTraversal(head);
	cout<<head->size;	
}
