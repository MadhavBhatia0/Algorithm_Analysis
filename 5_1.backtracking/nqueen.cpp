#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
            b[i]=s;
        }
        helper(n,0,ans,b);
        return ans;
    }

    void helper(int n,int row,vector<vector<string>>& ans,vector<string>& b) {
        if(row==n) {
            ans.push_back(b);
            return;
        }
        for(int j=0;j<n;j++) {
            if(possible(n,row,j,b)) {
                b[row][j]='Q';
                helper(n,row+1,ans,b);
                b[row][j]='.';
            }
        }
    }

    bool possible(int n,int row,int col,vector<string>& b) {
        for(int i=row-1;i>=0;i--) {
            if(b[i][col]=='Q')
            return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--) {
            if(b[i][j]=='Q')
            return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++) {
            if(b[i][j]=='Q')
            return false;
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(n);

    cout << "Number of solutions: " << result.size() << endl;
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
