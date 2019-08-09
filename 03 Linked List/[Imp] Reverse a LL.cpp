/*
Problem:
Given a linked list of N nodes. The task is to reverse this list. So, reverse the linked list and return head of the modified list.

Input:
6
1 2 3 4 5 6
5
2 7 8 9 10

Output:
6 5 4 3 2 1
10 9 8 7 2


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

/************************************************* Iteratively *************************************************/

Node* ReverseLL(Node *head)
{
  if(head==NULL || head->next==NULL)
    return head;
    
  Node* current = head;
  Node* previous = NULL;  
  Node* temp = current->next;
  while(current!=NULL)
  {
    temp = current->next;
    current->next = previous;
    previous = current;
    current = temp;
  }
  head = previous;
  return head;
}

/************************************************* Recursively *************************************************/

Node* ReverseLL(Node *head)
{
  if(head == NULL || head->next == NULL)
    return head;
  
  Node* ans = reverseLL(head->next);
  
  head->next->next = head;
  head->next = NULL; 
  
  return ans;
}
