/*
Problem:
Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i)  A Next pointer to the next node.
(ii) A Bottom pointer to a linked list where this node is head.
You have to flatten the linked list to a single linked list which is sorted. Return a pointer to the flattened linked list.

        
        Before Flattening                                                  After Flattening
        -----------------                                                  ----------------
        
       5 -> 10 -> 19 -> 28                         5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
       
The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.

Input:                   
4                                     // N
4 2 3 4                               // N numbers (M1, M2...Mn) denoting number of elements in linked lists starting with each head
5 7 8 30 10 20 19 22 50 28 35 40 45   // 1st head node and covering all the elements through its down pointer and so on

Output:
5 7 8 10 19 20 22 28 30 35 40 45 50

HINT : The idea is to use Merge() process of merge sort for linked lists. 
       We use merge() to merge lists one by one. We recursively merge() the current list with already flattened list.
       The down pointer is used to link nodes of the flattened list.
       
/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

Node* Merge(Node* h1, Node* h2)
{
    Node* ans;
    
    if(h1 == NULL)
      return h2;
    if(h2 == NULL)
      return h1;
      
    if(h1->data < h2->data)
    {
        ans = h1;
        ans -> bottom = merge(h1->bottom, h2);
    }
    else
    {
        ans = h2;
        ans -> bottom = merge(h1, h2->bottom);
    }
    return ans;
}
    
Node *FlattenLinkedList(Node *root)
{
    if(root == NULL || root->next == NULL)
      return root;
      
    return merge(root, flatten(root->next));
}
