#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

Node *newNode(int data)
{
  Node *temp= new Node;
  temp->data= data;
  temp->next=NULL;
  return temp;
}
//This function will make 2 lists one with small values than x and greater value than x and then merge them
//Time Complexity-O(n)
//space Complexity-O(1)
Node *partition(Node *head, int x)
{
  Node *smallhead=NULL;
  Node *smalltail=NULL;
  Node *greaterhead=NULL;
  Node *greatertail=NULL;
  while(head!=NULL)
  {
    if(head->data < x)
    {
      if(smallhead==NULL)
      {
        smallhead=smalltail=head;
      }
      else
      {
        smalltail->next=head;
        smalltail=smalltail->next;
      }
    }
    else if(head->data >=x)
    {
      if(greaterhead==NULL)
      {
        greaterhead=greatertail=head;
      }
      else
      {
        greatertail->next=head;
        greatertail=greatertail->next;
      }
    }
    head=head->next;
  }
  //assign the last node of greater linked list as null, if not assigned it will go in an infinite loop
  if (greatertail != NULL)
        greatertail->next = NULL;

  //JOin the lists
  if(smallhead==NULL)
    return greaterhead;
  else if(greaterhead==NULL)
    return smallhead;
  else
  {
    smalltail->next=greaterhead;
    return smallhead;
  }
}


/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

// Driver program to run the case
int main()
{
    /* Start with the empty list */
    struct Node* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(2);
    cout<<"Before";
    printList(head);
    cout<<endl;
    cout<<"after"<<endl;
    int x = 3;
    head = partition(head, x);
    printList(head);
    return 0;
}
