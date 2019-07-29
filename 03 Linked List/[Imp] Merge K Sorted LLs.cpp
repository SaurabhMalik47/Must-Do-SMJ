/*
Problem:
Given K sorted linked lists of different sizes. 
The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8

Output:
1 2 3 4 5 5 6 7 8
1 2 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list      1 -> 2-> 3
2nd    list      4 -> 5
3rd    list      5 -> 6
4th    list      7 -> 8
The merged list will be 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node* Merge2SortedLLs(Node* head1,   Node* head2)
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
  
  Node* ans = Merge2SortedLLs(head1, head2);
  head -> next = ans;
  return head;
}
  
Node * MergeKSortedLLs(Node *a[], int k)
{
    Node * head = NULL;
    for(int i=0; i<k; i++)
    {
        head = Merge2SortedLLs(head, a[i]);
    }
    return head;
}
