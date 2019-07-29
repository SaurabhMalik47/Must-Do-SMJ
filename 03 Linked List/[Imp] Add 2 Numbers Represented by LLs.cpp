/*
Problem:
Given two numbers represented by two linked lists of size M and N. The task is to return a sum list.
The sum list which is a linked list representation of addition of two input numbers.

Input:
2
4 5
3
3 4 5

2
6 3
1
7

Output:
0 9 3  
0 7

Explaination:
5->4 // Linked list repsentation of 45.
5->4->3 // Linked list representation of 345.
0->9 ->3 // Linked list representation of 390 resultant linked list.


/****************************** Time Complexity : O(m + n) and Space Complexity : O(1) ******************************/

Node* AddTwoLLs(Node* head1, Node* head2) 
{
  if(head1 == NULL)
    return head2 ;
  if(head2 == NULL)
    return head1 ;
    
  Node *ans = new Node( (head1->data + head2->data )%10 );
  ans->next = addTwoLists(head1->next , head2->next);
  if( (head1->data + head2->data) >= 10 )
    ans->next = addTwoLists(ans->next, new Node(1));
  return ans;  
}
