/*
Problem:
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Input:
3
1 2 1
4
1 2 3 4

Output:
1
0

/****************************************************** Hint ******************************************************/

1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it back to the first half.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node* ReverseLL(Node *head)
{
  if(head == NULL || head->next == NULL)
    return head;
  
  Node* ans = reverseList(head->next);
  
  head->next->next = head;
  head->next = NULL; 
  
  return ans;
}


bool isPalindrome(Node *head)
{
  Node *h1 = head;
  bool ans;
  int len=0;
  while(h1!= NULL)
  {
    h1 = h1->next;
    len++;
  }
  
  if(len == 0 || len == 1)
    return 1;
    
  h1 = head;
  
  int mid = (len/2)-1;
  
  for(int i=0; i<=mid; i++)
  {
      h1 = h1->next;
  }
    
  Node* h2 = reverseLL(h1);
  
  for(int i=0; i<=mid; i++) 
  {
    if(head->data == h2->data)
    {
         ans = true;
         head = head->next;
         h2 = h2->next;
    }
    else
    {
      ans = false;
      break;
    }
  }
    return ans; 
}
