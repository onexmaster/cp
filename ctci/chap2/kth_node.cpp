#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

Node* newNode(int data)
{
  Node *temp=new Node;
  temp->data=data;
  temp->next=NULL;
  return temp;
}

//Asummptions k is always less than the length of the linked list and greater than 0
//Time Complexity-O(n)
//space Complexity-O(1)
int kth_node (Node *root , int k)
{
  Node *fast=root;
  Node *slow=root;
  //int length=0;
  while(fast!=NULL && k>0)
  {
    fast=fast->next;
    k--;
    //length++;
  }
  while(fast!=NULL)
  {
    fast=fast->next;
    slow=slow->next;
    //length++;
  }
  //if(k==0)
  return slow->data;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(13);
    start->next->next->next = newNode(14);
    start->next->next->next->next = newNode(15);
    start->next->next->next->next->next =
                                    newNode(16);
    start->next->next->next->next->next->next =
                                    newNode(17);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    printf("kth Node of the linked list is : \n");
    cout<<kth_node(start, 7);

    return 0;
  }
