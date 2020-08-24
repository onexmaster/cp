#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *right;
	Node *left;
};
Node *insert(Node *root,char data)
{
	if(root==NULL)
	{
		root =new Node();
		root->data=data;
		root->left=root->right=NULL;
		return root;
	}
	else if(root->data>=data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void bfs(Node *root)
{
	if(root==NULL)
		return;
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node *current=q.front();
		cout<<current->data;
		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);
		q.pop();
	}
}
int main()
{
	 Node *root=NULL;
	 root=insert(root,'M'); root=insert(root,'B');
	root=insert(root,'Q'); root=insert(root,'Z');
	root=insert(root,'A'); root=insert(root,'C');
	cout<<"Level-Order Traversal"<<endl;
	bfs(root);
}
