#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
		int value;
		Node* left;
		Node* right;
		int height;
};
Node* newnode(int key)
{
	Node* node=new Node();
	node->value=key;
	node->right=NULL;
	node->left=NULL;
	node->height=1;
	return node;
}
int height(Node* root)
{
	if(root==NULL) return 0;
	else return max(height(root->left),height(root->right))+1;
}
int getbalance(Node* root)
{
	return height(root->left)-height(root->right);
}
Node* RightR(Node* x)
{
	Node* y=x->left;
	
	x->left=y->right;
	y->right=x;
	
	y->height=height(y);
	x->height=height(x);
	
	return y;
}
Node* LeftR(Node* x)
{
	Node* y=x->right;
	
	x->right=y->left;
	y->left=x;
	
	y->height=height(y);
	x->height=height(x);
	
	return y;
}
Node* insert(Node *root,int key)
{
	if(root==NULL)return newnode(key);
	else if(key < root->value)root->left = insert(root->left,key);
	else if(key > root->value)root->right = insert(root->right,key);
	else return root;
	
	root->height=height(root);
	int balance=getbalance(root);
	if(balance>1) // LL OR LR
	{
		if(key < root->left->value)//LL
		{
			return RightR(root);
		}
		else //LR
		{
			LeftR(root->left);
			return RightR(root);
		}
	}
	if(balance<-1) //RR or RL
	{
		if(key > root->right->value)//RR
		{
			return LeftR(root);
		}
		else //RL
		{
			RightR(root->right);
			return LeftR(root);
		}
	}
	return root;
}
void preorder(Node *root)
{
	if(root!=NULL){
	cout<<root->value;
	preorder(root->left);
	preorder(root->right);}
}
int main()
{
	Node* root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,7);
	preorder(root);
	
}
