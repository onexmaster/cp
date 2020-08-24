#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
void print_list(Node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}
int main()
{
	Node *root;
	Node *node1;
	Node *node2;
	Node *node3;
	root=new Node();
	node1=new Node();
	node2= new Node();
	node3= new Node();
	//Add data into nodes 
	root->data=15;
	root->next=node1;
	node1->data=20;
	node1->next=node2;
	node2->data=25;
	node2->next=node3;
	node3->data=50;
	node3->next=NULL;
	print_list(root);
	return 0;
}

