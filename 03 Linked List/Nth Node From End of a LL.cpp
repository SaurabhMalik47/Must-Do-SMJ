/*
Problem:
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Input:
9 2
1 2 3 4 5 6 7 8 9
4 5
10 5 100 5

Output:
8
-1

Explanation:
Testcase 1: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end os 8.  
Testcase 2: In the second example, there are 4 nodes in linked list and we need to find 5th from end.  
Since 'n' is more than number of nodes in linked list, output is -1.
            
            
 /****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/
           
int getNthFromLast(Node *head, int n)
{
    Node* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    
    if(len<n)
      return -1;
    
    temp = head;
    for(int i=1; i<(len-n+1); i++)
    {
        temp = temp->next;
    }
    return temp->data;
}  
