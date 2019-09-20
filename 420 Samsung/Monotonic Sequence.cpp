#include <iostream> 
#include <math.h> 
#define SMALL_N 1000000 
#define LARGE_N 1000000000000000 
#define ll long long
using namespace std; 

ll func(ll a, ll b, ll c, ll n) 
{ 
	ll res = a * n; 
	ll logValue = floor(log2(n)); 
	res += b * n * logValue; 
	res += c * (n * n * n); 
	return res; 
} 

ll getPositionInSeries(ll a, ll b, ll c, ll k) 
{ 
	ll start = 1, end = SMALL_N; 

	if (c == 0) 
    { 
		end = LARGE_N; 
	} 
	ll ans = 0; 

    // Binary Search 
	while (start <= end) 
    { 
		ll mid = (start + end) / 2; 
		ll val = func(a, b, c, mid); 
		if (val == k) 
        { 
			ans = mid; 
			break; 
		} 

		else if (val > k) 
			end = mid - 1; 
		else 
			start = mid + 1; 
	} 
	return ans; 
} 

int main() 
{ 
	ll a, b, c, k; 
	cin>>a>>b>>c>>k;

	cout << getPositionInSeries(a, b, c, k); 

	return 0; 
} 

