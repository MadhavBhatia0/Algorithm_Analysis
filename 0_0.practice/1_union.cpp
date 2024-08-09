//union of two arr
#include <iostream>
#include <set>
using namespace std;
void Union(int a[], int n, int b[], int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    cout << "The union set of both arrays is :" << endl;
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
}

int main()
{
    int a[9] = { 12, 2, 5, 6, 2, 33, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 61, 8, 9, 42, 6, 5, 4 };
    Union(a, 9, b, 10);
}
// set contains only distinct elements in ascending order

// time complexity
// inseting one element log N
// inserting N elements Nlog N

//Auxiliary Space: O(N) for storing n elements in set