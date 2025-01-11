#include <bits/stdc++.h>
using namespace std;

#define V 5 

void printSolution(int x[]); 

bool isSafe(int v, bool matrix[V][V], int x[], int pos) 
{ 
    if (matrix [x[pos - 1]][ v ] == 0) 
        return false; 

    for (int i = 0; i < pos; i++) 
        if (x[i] == v) 
            return false; 

    return true; 
}

bool hamCycleUtil(bool matrix[V][V], int x[], int pos) 
{ 
    if (pos == V) 
    { 
        if (matrix[x[pos - 1]][x[0]] == 1) 
            return true; 
        else
            return false; 
    }

    for (int v = 1; v < V; v++) 
    { 

        if (isSafe(v, matrix, x, pos)) 
        { 
            x[pos] = v; 

            if (hamCycleUtil (matrix, x, pos + 1)) 
                return true; 

            x[pos] = -1; 
        } 
    } 
    return false; 
} 

bool hamCycle(bool matrix[V][V]) 
{ 
    int *x = new int[V]; 
    for (int i = 0; i < V; i++) 
        x[i] = -1; 

    x[0] = 0; 
    if (hamCycleUtil(matrix, x, 1) == false ) 
    { 
        cout << "\nSolution does not exist"; 
        return false; 
    } 

    printSolution(x); 
    return true; 
} 

void printSolution(int x[]) 
{ 
    for (int i = 0; i < V; i++) 
        cout << x[i] << " "; 

    cout << x[0] << " "; 
    cout << endl;
}

int main() 
{ 
    bool matrix2[V][V] = {{0, 1, 1, 0, 1}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 0}, 
                         {0, 1, 1, 0, 0}}; 
    hamCycle(matrix2); 
} 