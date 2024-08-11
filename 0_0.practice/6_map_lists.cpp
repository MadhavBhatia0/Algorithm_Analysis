#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<string> keys = {"cherry","apple", "banana"};
    vector<int> values = {1, 2, 3};

    if (keys.size() != values.size()) {
        cerr << "Error: Keys and values lists must be of the same size." << endl;
        return 0;
    }
    map<string, int> dictionary;
    for (size_t i = 0; i < keys.size(); ++i) {
        dictionary[keys[i]] = values[i];
    }
    cout << "Mapped dictionary:" << endl;
    for (auto& pair : dictionary) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
