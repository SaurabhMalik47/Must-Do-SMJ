#include<iostream> 
using namespace std; 
#define MAX 3 

int fishspot[100]; // fishing spots 
int gate[MAX]; // position of gates 
int fishermen[MAX]; // no of fishermen at each gate 
int N; // total no of fishing spots 
int visited[MAX]; // occupied fishing spots 
int Answer; // result 

class FISH
{ 
    public : 
    void reset_fishspot(int index) 
    {  
	    for(int i=1; i<=N; i++) 
		    if (fishspot[i] == index + 1) 
			    fishspot[i] = 0; 
    } 

int calculate_distance(int index, int*pos1, int *pos2, int *score) 
{ 
	int i, sum = 0, left_min = 999999, right_min = 999999, left, right, npos = 0; 
	*pos1 = *pos2 = *score = 0; 
	left = right = gate[index]; 

	for (i = 1; i < fishermen[index]; i++) 
	{ 
		if (fishspot[gate[index]] == 0) 
		{ 
			sum++; 
			fishspot[gate[index]] = index + 1; 
		} 
		else
		{ 
			left_min = right_min = 999999; 

			while ((left > 0) && (fishspot[left] > 0)) 
				left--; 

			while ((right <= N) && (fishspot[right] > 0)) 
				right++; 

			if ((left > 0) && (fishspot[left] == 0)) 
				left_min = gate[index] - left + 1; 

			if ((right <= N) && (fishspot[right] == 0)) 
				right_min = right - gate[index] + 1; 

			if (right_min == left_min) 
			{ 
				if ((fishermen[index] - i - 1) > 1) 
				{ 
					fishspot[left] = fishspot[right] = index + 1; 
					sum += (2 * left_min); 
					i++; 

					if (i == fishermen[index]) 
					{ 
						npos = 1; 
						*score = sum; 
						return npos; 
					} 
				} 
				else
				{ 
					sum += left_min; 
					fishspot[left] = index + 1; 
				} 
			} 
			else if (left_min < right_min) 
			{ 
				sum += left_min; 
				fishspot[left] = index + 1; 
			} 
			else if (right_min < left_min) 
			{ 
				sum += right_min; 
				fishspot[right] = index + 1; 
			} 
		} 
	} 

	left_min = right_min = 99999; 

	while ((left > 0) && (fishspot[left] > 0)) 
		left--; 

	if ((left > 0) && (fishspot[left] == 0)) 
		left_min = gate[index] - left + 1; 

	while ((right <= N) && (fishspot[right] > 0)) 
		right++; 

	if ((right <= N) && (fishspot[right] == 0)) 
		right_min = right - gate[index] + 1; 

	if ((sum + left_min) == (sum + right_min)) 
	{ 
		npos = 2; 
		*pos1 = left; 
		*pos2 = right; 
		*score = sum + left_min; 
	} 
	else if ((sum + left_min) > (sum + right_min)) 
	{ 
		npos = 1; 
		*score = sum + right_min; 
		fishspot[right] = index + 1; 
	} 
	else if ((sum + left_min) < (sum + right_min)) 
	{ 
		npos = 1; 
		*score = sum + left_min; 
		fishspot[left] = index + 1; 
	} 
	return npos; 
} 

void solve(int index, int sum, int count) 
{ 
	int npos, pos1, pos2, score, i; 

	visited[index] = 1; 

	if (sum > Answer) 
		return; 

	npos = calculate_distance(index, &pos1, &pos2, &score); 
	sum += score; 

	if (count == MAX) 
	{ 
		if (Answer > sum) 
			Answer = sum; 

		return; 
	} 

	if (npos == 1) 
	{ 
		for (i = 0; i < MAX; i++) 
		{ 
			if (visited[i] == 0) 
			{ 
				solve(i, sum, count + 1); 
				visited[i] = 0; 
				reset_fishspot(i); 
			} 
		} 
	} 
	
	else if (npos == 2) 
	{ 
		fishspot[pos1] = index + 1; 
		for (i = 0; i < MAX; i++) 
		{ 
			if (visited[i] == 0) 
			{ 
				solve(i, sum, count + 1); 
				visited[i] = 0; 
				reset_fishspot(i); 
			} 
		} 

		fishspot[pos1] = 0; 
		fishspot[pos2] = index + 1; 
		for (i = 0; i < MAX; i++) 
		{ 
			if (visited[i] == 0) 
			{ 
				solve(i, sum, count + 1); 
				visited[i] = 0; 
				reset_fishspot(i); 
			} 
		} 
		fishspot[pos2] = 0; 
	} 
} 
}; 
int main()
{ 
        FISH f;
        int i; 
        cin >> N;
        
        for (i = 0; i < MAX; i++) 
            cin>>gate[i];
        for(i=0; i<MAX; i++)
            cin>>fishermen[i]; 
        for(i=0; i<MAX; i++)
            visited[i] = 0; 
          

        for (i = 1; i <= N; i++) 
            fishspot[i] = 0; 
  
        Answer = 999999; 
  
        for (i = 0; i < MAX; i++) 
        { 
            f.solve(i, 0, 1); 
            visited[i] = 0; 
            f.reset_fishspot(i); 
        } 
  
       cout << Answer << endl;
      
    return 0; 
}




/*
Sample Input: 
10
4 6 10
5 2 2

Sample Output:
18
*/
