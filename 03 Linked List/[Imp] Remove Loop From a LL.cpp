/*
Problem:
You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Input:
3
1 3 4
2

4
1 8 3 4
0

Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.
The linked list with nodes N = 3 is given. Here, x = 2 which means last node is connected with xth node of linked list. 
Therefore, there exists a loop. 

Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

void removeIt(Node* head, Node* fast)
{
    Node* slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    while(slow->next != fast)
    {
        slow = slow->next;
    }
    slow->next = NULL;
}

void removeTheLoop(Node *head)
{
   Node* slow = head;
   Node* fast = head;

   while(slow && fast && fast->next)
   {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
       {
          removeIt(head, fast);
          return;
       }
   }
}
