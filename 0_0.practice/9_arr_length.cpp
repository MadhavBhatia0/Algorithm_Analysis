#include <iostream>
#include <vector>
using namespace std;
int findLength(vector<int>& arr, int index = 0) {
    if(index==arr.size())
    return 0;
    return 1+findLength(arr,index+1);
}

int easier(vector<int>& arr)
{
    return arr.size();
}
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    int length = findLength(arr);
    cout << "The length of the arr is: " << length << endl;

    int len2=easier(arr);
    cout<<len2;
}