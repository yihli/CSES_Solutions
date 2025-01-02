#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// recursive function to add permutations to unordered map
// unordered map prevents any duplicated strings if case of 2+ similar characters
void permute(unordered_map<string, string>& umap, vector<string>& keys, string& s, int index) {

    // base case: when the string is done 
    if (index == s.size()) {

        // if the key does not exist yet, add it to the map and add the key to array
        if (umap.find(s) == umap.end()) {
            umap[s] = s;
            keys.push_back(s);
        }
        return;
    }

    // permutations are created by swapping two letters at a time and backtracking.
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        permute(umap, keys, s, index + 1);
        swap(s[index], s[i]);
    }
    
}

// create all permutations of the string and put into unordered_map so there are no dupes
// at the same time,  put keys in an array 
// sort array by alphabetical and then print the map elements using the array's keys.
int main() {
    string s;
    unordered_map<string, string> umap;
    vector<string> keys;

    cin >> s;

    permute(umap, keys, s, 0);

    cout << keys.size() << '\n';
    // sort(keys.begin(), keys.end());
    //vector<int>::iterator iter = keys.begin();
    
    for (auto iter = keys.begin(); iter != keys.end(); iter++) {
        cout << *iter;
        cout << '\n';
    }
    
}