#include <iostream>
#include <queue>
using namespace std;
class Node
{
	public:
	int data;
	Node* right;
	Node* left;
	static Node* NewNode(int data)
	{
		Node* n = new Node();
		n->data=data;
		n->left=NULL;
		n->right=NULL;
		return n;
	}
};

class AVLTree{
	public:
	static int height(Node* root)
	{
		if(root==NULL){return 0;}
		int Lheight = height(root->left);
		int Rheight = height(root->right);
		return std::max(Lheight,Rheight)+1;
	}
	Node* addNode(int data,Node* root)
	{
		Node* head = root;
		if(root==NULL){ root=Node::NewNode(data); return root;}
		else
		{
			Node* parent;
			while(root!=NULL)
			{
				parent=root;
				if(data<parent->data){root=root->left;}
				else{root=root->right;}
			}
			if(parent->data<data){parent->right=Node::NewNode(data);}
			else{parent->left=Node::NewNode(data);}
		}
		int balance = AVLTree::height(head->left)- AVLTree::height(head->right);
		root=head;
		if(balance<-1 || balance >1)
		{
			Node* ImbalancedNode;
			while(balance<-1 || balance>1)
			{ 
				ImbalancedNode = root;
				if(balance<-1) { root=root->right; }
				else{ root=root->left; }
				balance = AVLTree::height(root->left)-AVLTree::height(root->right);
			}
			balance= AVLTree::height(ImbalancedNode->left) - AVLTree::height(ImbalancedNode->right);
			if(balance<-1)
			{
				if(AVLTree::height(ImbalancedNode->right->right) > AVLTree::height(ImbalancedNode->right->left))
				{
					//RR
					Node* tempNode = ImbalancedNode->right->left;
					ImbalancedNode->right->left=NULL;
					Node* tempNode1 = ImbalancedNode->right;
					int temp = ImbalancedNode->data;
					ImbalancedNode->data=ImbalancedNode->right->data;
					ImbalancedNode->right=ImbalancedNode->right->right;
					tempNode1->right=NULL;
					if(ImbalancedNode->left!=NULL){
						tempNode1->data=ImbalancedNode->left->data;
						ImbalancedNode->left->left=tempNode1;
						}
					else{ImbalancedNode->left=tempNode1;}
					ImbalancedNode->left->right=tempNode;
					ImbalancedNode->left->data=temp;
				}
				else
				{
					//RL
					Node* tempNode2 = ImbalancedNode->right->right;
					ImbalancedNode->right->right=ImbalancedNode->right->left;
					ImbalancedNode->right->left=tempNode2;
					int temp3 ;
					if( ImbalancedNode->right->right->right!=NULL){
					temp3 = ImbalancedNode->right->right->right->data;}
					if(tempNode2!=NULL )
					{
						ImbalancedNode->right->right->right->data=tempNode2->data;
						ImbalancedNode->right->left->data=temp3;
					}
					temp3 = ImbalancedNode->right->data;
					ImbalancedNode->right->data=ImbalancedNode->right->right->data;
					ImbalancedNode->right->right->data=temp3;
					//RR
					Node* tempNode = ImbalancedNode->right->left;
					ImbalancedNode->right->left=NULL;
					Node* tempNode1 = ImbalancedNode->right;
					int temp = ImbalancedNode->data;
					ImbalancedNode->data=ImbalancedNode->right->data;
					ImbalancedNode->right=ImbalancedNode->right->right;
					tempNode1->right=NULL;
					if(ImbalancedNode->left!=NULL){
						tempNode1->data=ImbalancedNode->left->data;
						ImbalancedNode->left->left=tempNode1;
						}
					else{ImbalancedNode->left=tempNode1;}
					ImbalancedNode->left->right=tempNode;
					ImbalancedNode->left->data=temp;
					
				}
			}
			else
			{
				if(AVLTree::height(ImbalancedNode->left->left) > AVLTree::height(ImbalancedNode->left->right))
				{
					//LL
					Node* tempNode = ImbalancedNode->left->right;
					ImbalancedNode->left->right=NULL;
					Node* tempNode1 = ImbalancedNode->left;
					int temp = ImbalancedNode->data;
					ImbalancedNode->data=ImbalancedNode->left->data;
					ImbalancedNode->left=ImbalancedNode->left->left;
					tempNode1->left=NULL;
					if(ImbalancedNode->right!=NULL){
						tempNode1->data=ImbalancedNode->right->data;
						ImbalancedNode->right->right=tempNode1;
						}
					else{ImbalancedNode->right=tempNode1;}
					ImbalancedNode->right->left=tempNode;
					ImbalancedNode->right->data=temp;
				}
				else
				{
					//LR
					Node* tempNode2 = ImbalancedNode->left->left;
					ImbalancedNode->left->left=ImbalancedNode->left->right;
					ImbalancedNode->left->right=tempNode2;
					int temp3 ;
					if( ImbalancedNode->left->left->left!=NULL){
					temp3 = ImbalancedNode->left->left->left->data;}
					if(tempNode2!=NULL )
					{
						ImbalancedNode->left->left->left->data=tempNode2->data;
						ImbalancedNode->left->right->data=temp3;
					}
					temp3 = ImbalancedNode->left->data;
					ImbalancedNode->left->data=ImbalancedNode->left->left->data;
					ImbalancedNode->left->left->data=temp3;
					//LL
					Node* tempNode = ImbalancedNode->left->right;
					ImbalancedNode->left->right=NULL;
					Node* tempNode1 = ImbalancedNode->left;
					int temp = ImbalancedNode->data;
					ImbalancedNode->data=ImbalancedNode->left->data;
					ImbalancedNode->left=ImbalancedNode->left->left;
					tempNode1->left=NULL;
					if(ImbalancedNode->right!=NULL){
						tempNode1->data=ImbalancedNode->right->data;
						ImbalancedNode->right->right=tempNode1;
						}
					else{ImbalancedNode->right=tempNode1;}
					ImbalancedNode->right->left=tempNode;
					ImbalancedNode->right->data=temp;
				}
			}
		}
		return head;
		
	}
};
//--------------------------------Level order traversal--------------------------------------------------------------
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
//--------------------------------------------------------------------
int main()
{
	AVLTree *At = new AVLTree();
	Node *head = NULL;
	head = At->addNode(13,head);
	head = At->addNode(10,head);
	head = At->addNode(15,head);
	head = At->addNode(5,head);
	head = At->addNode(11,head);
	head = At->addNode(16,head);
	head = At->addNode(4,head);
	head = At->addNode(6,head);
	head = At->addNode(3,head);
	LevelOrderTraversal(head);
}
