/*
Problem:
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node *kReverse (Node *head, int k)
{ 
  if(head==NULL || head->next==NULL)
    return head;
    
  Node* current = head;
  Node* previous = NULL;  
  Node* temp = current->next;
  int count = 0;

  while(current!=NULL && count < k)
  {
    temp = current->next;
    current->next = previous;
    previous = current;
    current = temp;
    count++;
  }

  if(temp!=NULL)
    head->next = reverse(temp, k);
  
  return previous;
}
