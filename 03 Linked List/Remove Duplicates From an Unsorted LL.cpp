/*
Problem:
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. 
If all the nodes in the linked list are equal, then remove n-1 nodes.

Input:
4
5 2 2 4
5
2 2 2 2 2

Output:
5 2 4
2


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node * RemoveDuplicates(Node *root)
{
  unordered_set<int> s ;
  Node *current = root ;
  Node *previous = NULL ;
  while(current != NULL)
  {
    if(s.count(current->data) == 1)
    {
        previous->next  = current->next ;
        free(current) ;
    }
    else
    {
        s.insert(current->data) ;
        previous = current ;
    }
    current = current->next ;
   }
   return root;
}
