#include <bits/stdc++.h> 
using namespace std; 

int findMedian(vector<int> a) 
{ 
    int n=a.size();
	if (n % 2 == 0) {  
		nth_element(a.begin(), a.begin() + n / 2, a.end()); 
		nth_element(a.begin(), a.begin() + (n - 1) / 2, a.end()); 
		return (a[(n - 1) / 2] + a[n / 2])/2; 
        // n/2th and n-1/2th element are in there place as it should be in the sorted array
	} 
	else { 
		nth_element(a.begin(), a.begin() + n / 2, a.end()); 
		return a[n / 2]; 
	} 
}
int main() 
{ 
    vector<int> arr = { 1, 3, 4, 2, 7, 5, 8, 6 }; 
	cout << "Median = "<< findMedian(arr) << endl; 
}
// time O(n)
// space O(1)
