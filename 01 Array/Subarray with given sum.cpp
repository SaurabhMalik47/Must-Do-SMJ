/********************** Time Comp : O(n) ***********************/

void findSubArray(int a[], int n, int sum)
{
    bool found = false;
    int current_sum = 0, start = 0;
    for(int i=0; i<n; i++)
    {
        current_sum += a[i];
        while(current_sum>sum && start<=i)
        {
            current_sum -= a[start];
            start++;
        }
        if(current_sum == sum)
        {
           found = true;
           cout<<start+1 <<" " << i+1 ;
           break;
        }
    }
    if(found == false)
       cout<<"-1";
}
