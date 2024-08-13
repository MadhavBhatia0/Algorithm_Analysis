#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>> createDictionary(const string& input) {
    map<char, vector<string>> wordDictionary;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        char firstChar = word[0];
        wordDictionary[firstChar].push_back(word);
    }
    return wordDictionary;
}

int main() {
    string input = "apple ant bat ball cat car dog dove eagle";
    map<char, vector<string>> wordDictionary = createDictionary(input);

    for (const auto& pair : wordDictionary) {
        cout << "Words starting with '" << pair.first << "': ";
        for (const string& word : pair.second) {
            cout << word << " ";
        }
        cout << endl;
    }
}
