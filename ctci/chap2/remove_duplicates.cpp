#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

Node* newNode (int data)
{
  Node *temp= new Node;
  temp->data= data;
  temp->next= NULL;
  return temp;
}

//Time Complexity-O(n);
//space Complexity-O(n);
void remove_duplicates(Node *root)
{
  unordered_set<int>st;
  Node *curr=root;
  Node *pre=NULL;
  while(curr!=NULL)
  {
    if(st.find(curr->data)!=st.end())//we have a duplicate
    {
      pre->next=curr->next;
      delete(curr);
    }
    else
    {
      st.insert(curr->data);
      pre=curr;
    }
    curr=pre->next;
  }
}
//Using two loops
//Time Complexity-O(n^2)
//space Complexity-O(1)
void removeDuplicates(Node *root)
{
   Node *ptr1, *ptr2, *dup;
    ptr1 = root;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next!= NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}




void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(11);
    start->next->next->next->next->next =
                                    newNode(11);
    start->next->next->next->next->next->next =
                                    newNode(10);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(start);

    return 0;
}
