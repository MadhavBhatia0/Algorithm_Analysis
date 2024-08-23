#include<iostream>
#include <utility>
using namespace std;

pair<int,int> search(int arr[],int n)
{
    int i,max,min;
    if(n%2==1)
    {
        max=arr[0];
        min=arr[0];
        i=1;
    }
    else{
        if(arr[0]>arr[1])
        {
            max=arr[0];
            min=arr[1];
        }
        else{
            max=arr[1];
            min=arr[0];
        }
        i=2;
    }
    while(i<n)
    {
        if(arr[i]<arr[i+1])
        {
            if(arr[i]<min)
            min=arr[i];
            if(arr[i+1]>max)
            max=arr[i+1];
        }
        else{
            if(arr[i]>max)
            max=arr[i];
            if(arr[i+1]<min)
            min=arr[i+1];
        }
        i+=2;
    }
    return {max,min};
}
int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
	int n = sizeof(arr)/sizeof(arr[0]);
    
    pair<int,int> res=search(arr,n);
    cout<<"Max is "<<res.first <<" and min is "<< res.second;
}
// it takes O(n) but number of comparisons are less 
// better than brute approach