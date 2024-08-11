//Remove the “i” th occurrence of the given word in a list where words repeat

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> RemoveNthWord(vector<string> lst, const string& word, int N) {
    vector<string> newList;
    int count = 0;

    for (auto i : lst) {
        if (i == word) {
            count++;
            if (count != N) {
                newList.push_back(i);
            }
        } else {
            newList.push_back(i);
        }
    }

    if (count == 0) {
        cout << "Item not found" << endl;
    } else {
        cout << "Updated list is: ";
        for (auto i : newList) {
            cout << i << " ";
        }
        cout << endl;
    }
    return newList;
}

int main() {
    vector<string> list = {"hello", "world", "hello"};
    string word = "hello";
    int N = 2;

    vector<string> result= RemoveNthWord(list, word, N);
}
