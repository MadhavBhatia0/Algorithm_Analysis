#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char S, char H,char D)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, S, D, H);
    cout << "Move disk " << n << " from rod " << S << " to rod " << D << endl;
    towerOfHanoi(n - 1, H, S, D);
}
int main()
{
    int N = 3;
    towerOfHanoi(N, 'S', 'H', 'D');
}
// move n-1 discs from source to helper using destination
// move nth disk to destination
// move n-1 disk from helper to destination using source