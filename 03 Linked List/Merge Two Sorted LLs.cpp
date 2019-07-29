/*
Problem:
Given two sorted linked lists consisting of M and N nodes respectively.
The task is to merge both of the list (in-place) and return head of the merged list.

Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
4 3
5 10 15 40 
2 3 20

2 2
1 1
2 4 

Output:
2 3 5 10 15 20 40 
1 1 2 4


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

/************************************************* Method - 1 **************************************************/

Node* sortedMerge(Node* head1,   Node* head2)
{
  if(head1==NULL)
    return head2;
  if(head2==NULL)
    return head1;
  
  Node* head;
  
  if(head1->data < head2->data)
  {
    head = head1;
    head1 = head1 -> next;
  }
  
  else
  {
    head = head2;
    head2 = head2 -> next;
  }
  
  Node* ans = sortedMerge(head1, head2);
  head -> next = ans;
  return head;
}

/************************************************* Method - 2 **************************************************/

Node* SortedMerge(Node* head1, Node* head2)
{
    if(!head1)
      return head2;
    if(!head2)
      return head1;
      
    if(head1->data < head2->data)
    {
        head1->next = SortedMerge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = SortedMerge(head1, head2->next);
        return head2;
    }
}
