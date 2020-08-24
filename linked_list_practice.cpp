#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
void insert_begin(Node *&head, int val)
{
	Node *x=new Node();
	x->data=val;
	x->next=head;
	head=x;
}
void insert_end(Node *&head, int val)
{
	Node *current=head;
	while(current->next!=NULL)
		current=current->next;
	Node *y=new Node();
	y->data=val;
	current->next=y;
	y->next=NULL;
}
void print_list(Node *head)
{
	Node *current=head;
	while(current->next!=NULL)
	{
		cout<< current->data <<" ";
		current=current->next;
	}
	cout<< current->data;
}

int main()
{
	Node *head=new Node();
	head->data=50;
	head->next=NULL;
	insert_begin(head,15);
	insert_begin(head,25);
	insert_end(head,150);
	print_list(head);
	return(0);
}
