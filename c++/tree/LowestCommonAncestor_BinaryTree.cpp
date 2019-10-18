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
//-----------------LowestCommonAncestor--------------------------------
Node* LCA(Node* root,int key1,int key2)
{
	if(root==NULL){return NULL;}
	if(root->left==NULL && root->right==NULL)
	{
		if(root->data==key1 || root->data==key2) { return root;}
		else return NULL;
	}
	if(root->data==key1 || root->data==key2){return root;}
	Node* L=LCA(root->left,key1,key2);
	Node* R=LCA(root->right,key1,key2);
	if(L!=NULL && R!=NULL){return root;}
	if(L==NULL && R==NULL){return NULL;}
	if(L!=NULL){return L;}
	return R;
}
using namespace std;
int main()
{
	BinaryTree *bt = new BinaryTree();
	Node *head=NULL;
	head=bt->addNode(head,10);
	head=bt->addNode(head,20);
	head=bt->addNode(head,30);
	head=bt->addNode(head,40);
	head=bt->addNode(head,50);
	head=bt->addNode(head,60);
	head=bt->addNode(head,70);
	head=bt->addNode(head,80);
	head=bt->addNode(head,90);
	head=bt->addNode(head,100);
	//LevelOrderTraversal(head);
	cout<<LCA(head,100,90)->data;
	
	
}
