/*
Problem:
Given a singly linked list consisting of N nodes. 
The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).

Input:
4
5 2 2 4
5
2 2 2 2 2

Output:
2 4 5
2


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node *RemoveDuplicates(Node *head)
{
    Node *temp = head;
    Node *tail;
       
    if(temp == NULL)
      return NULL;
      
    while(temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            tail = temp->next->next;
            free(temp->next);
            temp->next = tail;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;  
}
