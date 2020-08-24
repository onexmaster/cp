#include<bits/stdc++.h>
using namespace std;
struct Node {
	char data;
	Node *left;
	Node *right;
};
void inorder(Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
void preorder(Node *root)
{
	if(root== NULL)
		return;
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node *root)
{
	if( root ==  NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}
Node *insert(Node *root, char data)
{
	if(root==NULL)
	{
		root=new Node();
		root->data=data;
		root->right=root->left=NULL;
		return root;
	}
	else if(root->data >= data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
int main()
{
	Node *root=NULL;
	root=insert(root,'M'); root=insert(root,'B');
	root=insert(root,'Q'); root=insert(root,'Z');
	root=insert(root,'A'); root=insert(root,'C');
	cout<<"inorder"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"preorder"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"postorder"<<endl;
	postorder(root);
}
	
