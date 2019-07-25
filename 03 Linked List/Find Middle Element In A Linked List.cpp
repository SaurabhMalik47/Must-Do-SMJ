/*
Problem:
Given a singly linked list of N nodes. The task is to find middle of the linked list. 
For example, if given linked list is 1->2->3->4->5 then output should be 3. 

Input:
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
3
7


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

int getMiddle(Node *head)
{
   Node* temp = head;
   int len=0;
   while(temp != NULL)
   {
       len++;
       temp = temp->next;
   }
   
   if(len == 0)
     return -1;
     
   else
   {
       for(int i=0; i<(len)/2; i++)
       {
           head = head->next;
       }
       return head->data;
   }  
}
