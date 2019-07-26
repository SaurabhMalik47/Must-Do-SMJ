/*
Problem:
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes,
where k is a given positive integer smaller than or equal to length of the linked list.

Input:
8                      // n
1 2 3 4 5 6 7 8
4                      // k

5
2 4 7 8 9
3

2
1 2
4

Output:
5 6 7 8 1 2 3 4
8 9 2 4 7
1 2

Explanation:
Testcase 1: After rotating the linked list by 4 elements (anti-clockwise), we reached to node 5, 
which is (k+1)th node from beginning, now becomes head and tail of the linked list is joined to the previous head.

/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node* RotateLL(Node* head, int k) 
{
  Node* temp = head;
  while(temp->next)
  {
      temp = temp->next;
  }
  temp->next = head;
  
  Node* end;
  while(k--)
  {
      end = head;
      head = head->next;
  }
  end->next = NULL;
  return head;
}
