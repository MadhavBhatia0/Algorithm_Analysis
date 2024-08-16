#include<iostream>
using namespace std;

int search(int arr[],int ele,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int ele;
    cout<<"enter a number";
    cin>>ele;
    int res=search(arr,ele,size);
    cout<<"found at "<<res<<" index";
}
// space O(1)
// time  O(n)