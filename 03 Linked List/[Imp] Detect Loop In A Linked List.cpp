/*
Problem:
Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

Input:
3
1 3 4
2

4
1 8 3 4
0

Output:
True
False

Explaination:
Testcase 1: N = 3. The linked list with nodes N = 3 is given. Then value of x=2 is given which means that last node is 
connected with xth node of linked list. Therefore, there exists a loop. 

Testcase 2: For N = 4
x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

bool DetectLoop(Node *head) 
{   
    Node* slow = head;
    Node* fast = head;
   
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
       
        if(slow == fast)
            return true;
    }
    return false;
}
