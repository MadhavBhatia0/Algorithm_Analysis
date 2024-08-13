#include<bits/stdc++.h>
using namespace std;

map<string, int> countWordFrequency(const string& input) {
    map<string, int> wordFrequency;
    stringstream ss(input); //we can directly write and extract data from stringstream
    string word;

    while (ss >> word) {  // only the string part of input will be assigned to word
        for (auto& ch : word) {
            ch = tolower(ch);
            if (ispunct(ch)) { // to check if there is any panctuation
                ch = '\0';
            }
        }
        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    return wordFrequency;
}

int main() {
    string input = "This is a test. This test is only a test.";
    map<string, int> wordFrequency = countWordFrequency(input);
    for (const auto& pair : wordFrequency) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }
}
// if we declare int and write ss>>num, then only int part of input will be assigned to num
// works similar to cin and cout 
