/*
Problem:
Given a singly linked list of size N. The task is to swap elements pairwise.

Input:
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7

Explanation:
After swapping each pair considering (1,2), (2, 4), (5, 6), (7, 8) as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as new linked list.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

/************************************************* Method - 1 **************************************************/

void PairWiseSwap(Node *head)
{
    if(head==NULL || head->next==NULL)
      return;
      
    int temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
    pairWiseSwap(head->next->next);
}

/************************************************* Method - 2 **************************************************/

void pairWiseSwap(Node *head)
{
   while(head!=NULL && head->next!=NULL)
   {
       int temp = head->data;
       head->data = head->next->data;
       head->next->data = temp;
       head = head->next->next;
   }
}
