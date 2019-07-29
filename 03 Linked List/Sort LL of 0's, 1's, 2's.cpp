/*
Problem:
Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only. 
The task is to segregate 0s, 1s and 2s linked list such that all zeros segregate to headside, 
2s at the end of the linked list and 1s in the mid of 0s and 2s.

Input:
8
1 2 2 1 2 0 2 2
4
2 2 0 1

Output:
0 1 1 2 2 2 2 2
0 1 2 2


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node* sort0s1s2s(Node *head) 
{
  int count0 = 0, count1 = 0, count2 = 0;
  Node* temp = head;
  while(temp != NULL)
  {
    if(temp->data == 0)
      count0++;
    else if(temp->data == 1)
      count1++;
    else
      count2++;
        
    temp = temp ->next;
  }
    
  temp=head;

  while(count0-- )
  {
     temp->data = 0;
     temp = temp->next;
  }
    
  while(count1--)
  {
     temp->data = 1;
     temp = temp->next;
  }
    
  while(count2--)
  {
     temp->data = 2;
     temp = temp->next;
  }     
  return head;
}
