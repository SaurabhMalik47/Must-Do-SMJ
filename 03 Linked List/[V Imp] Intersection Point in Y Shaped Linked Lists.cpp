/*
Problem:
There are two singly linked lists of size N and M in a system. But, due to some programming error the end node of one of the linked list
got linked into one of the node of second list, forming a inverted Y shaped list. 
Write a program to get the point where two linked lists intersect each other. You should return data of intersection point of 
two linked lists head1 and head2. If there is no intersecting point, then return -1.

First line contains three numbers, 
1) x - Number of nodes before merge point in 1st list
2) y - Number of nodes before merge point in 2nd list
3) z - Number of nodes after merge point
Next three lines contain x, y and z values.

Input:
2 3 2
10 20
30 40 50
5 10

2 3 2
10 20
30 40 50
10 20

Output:
5
10


/****************************** Time Complexity : O(m + n) and Space Complexity : O(1) ******************************/

// Function to Calculate Length
int length(Node* head)
{
  Node* temp = head;
  int len = 0;
  while(temp != NULL)
  {
     len++; 
     temp = temp->next;
  }
  return len;
}

// Function to Find Desired Answer
int intersectPoint(Node* head1, Node* head2)
{
    // Calculate Length of Both LLs as len1 & len2
 
    int len1 = length(head1);
    int len2 = length(head2);
    
    //Calculate the Absolute Difference i.e diff = |len1-len2|
    
    int diff = abs(len1-len2);

    //Check Which LL is Longer & then traverse "diff" nodes in Longer LL
    if(len1>len2)
    {
       while(diff--)
          head1 = head1 -> next;
    }
    
    else
    {
       while(diff--)
          head2 = head2 -> next;
    }
    
    //Now, Move Both LLs by 1 Step till Both are not equal
    while(head1 != NULL && head2 != NULL)
    {
       if(head1 == head2)
       {
          return head1->data;
       }
       
       else
       {   
          head1 = head1 -> next;
          head2 = head2 -> next;
       }
     }
     return -1;
}
