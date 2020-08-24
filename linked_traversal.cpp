#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};
void insert_begin(Node *&head, int val)
{
	Node* node4= new Node();
	node4->data=val;
	node4->next=head;
	head=node4;
}
void insert_end(Node *&head, int val)
{
	Node* current= head;
	while(current->next!=NULL)
	{
	current=current->next;
	}
	Node* new_node= new Node();
	new_node->data=val;
	new_node->next=NULL;
	current->next=new_node;
}

void print_list(Node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}
void length(Node *n)
{
	int count=0;
	while(n!=NULL)
	{
		count++;
		n=n->next;
	}
	cout<<count;
}
int main()
{
 	Node* head=new Node();
	Node* data1=new Node();
	head->data=45;
	head->next=data1;
	data1->data=50;
	data1->next=NULL;
	insert_begin(head,20);
	insert_begin(head,100);
	insert_end(head,110);
	insert_end(head,200);
	print_list(head);
	length(head);
	return 0;
}
