//Given a linked list return wether it is a palindrome or not

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

Node *newNode(int data)
{
  Node *temp=new Node();
  temp->data=data;
  temp->next=NULL;
  return temp;
}
//Time Complexity- O(n)
//Space Complexity-O(n)
bool palindrome(Node *root)
{
  stack<int>st;
  Node* dummy=root;
  while(dummy!=NULL)
  {
    st.push(dummy->data);
    dummy=dummy->next;
  }
  while(root!=NULL)
  {
    int data=st.top();
    st.pop();
    if(data!=root->data)
      return false;
    root=root->next;
  }
  return true;
}
//Fucntion to revserse the linked lists
Node *linked_list_reverse(Node *root)
{
  Node *previous=NULL;
  Node *current=root;
  Node *forward=root;
  while(current!=NULL)
  {
    forward=current->next;
    current->next=previous;
    previous=current;
    current=forward;
  }
  return previous;
}
//Function to find the middle node of the linked list
Node *middle_node(Node *root)
{
  Node *slow=root;
  Node *fast=root;
  while(fast->next!=NULL && fast->next->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
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


//Todo to do it in place
//Time Complexity- O(n)
//Space Complexity-O(1)
bool is_palindrome(Node *root)
{ /*
   1-Find the middle node of the linked list using 2 pointers.
   2-Reverse the second half
   3-Check for palinrdome
   4-revese the second half again
   */
   Node *middle=middle_node(root);
   Node *secondhalf=linked_list_reverse(middle->next);
   Node *p1=root;
   Node *p2=secondhalf;
   cout<<"List after reverse"<<endl;
   printList(p2);
   cout<<endl;
   while(p2!=NULL)
   {
     if(p1->data != p2->data)
     {
        middle->next=linked_list_reverse(secondhalf);
       cout<<"Reversing the linked list to get original list"<<endl;
       printList(root);
       cout<<endl;
       return false;
     }
    p1=p1->next;
    p2=p2->next;
   }
   middle->next=linked_list_reverse(secondhalf);
   cout<<"Reversing the linked list to get original list"<<endl;
   printList(root);
   cout<<endl;
   return true;

}







// Driver program to run the case
int main()
{
    /* Start with the empty list */
    struct Node* head = newNode(7);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(7);
    cout<<"Original List"<<endl;
    printList(head);
    cout<<endl;
    cout<<is_palindrome(head);
    return 0;
}
