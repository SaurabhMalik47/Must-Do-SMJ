/*
Problem:
You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
The task is to delete the node.

Note: No head reference is given to you.

Input:
2
1 2
1

4
10 20 4 30
20

Output:
2
10 4 30

Explanation:
Testcase 1: After deleting 20 from the linked list, we have remaining nodes as 10, 4 and 30.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

/************************************************* Method - 1 **************************************************/

void deleteNode(Node *node)
{
    *node = *(node->next);
}

/************************************************* Method - 2 **************************************************/

void deleteNode(Node *node)
{
   node->data = node->next->data;
   node->next = node->next->next;
}
