/*
Problem:
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7


/****************************** Time Complexity : O(m * n) and Space Complexity : O(n) ******************************/

void SpiralPrint(int **a, int m, int n)
{
  // m = row, n = column, rs = row_starting, re = row_ending, cs = column_starting, ce = column_ending
  int i, rs = 0, cs = 0, re = m-1, ce = n-1;
  
  while(rs<=re && cs<=ce)
  {
     for(i=cs; i<=ce; i++)
     {
       cout << a[rs][i] << " ";
     }
     rs++;
    
    
     for(i=rs; i<=re; i++)
     {
       cout << a[i][ce] << " ";
     }
     ce--;
    
    
     if(rs <= re)
     {
        for(i=ce; i>=cs; i--)
        {
           cout << a[re][i] << " ";
        }
        re--;
     }
     
    
    if(cs <= ce)
    {
       for(i=re ; i>=rs ; i--)
       {
          cout << a[i][cs] << " ";
       }
       cs++;
    }
  }
}
