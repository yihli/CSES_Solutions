#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    unordered_map<char, int> umap;
    vector<char> v;
    string s;
    char extra_letter = '-';
    int num_odds = 0;

    getline(cin, s);
    
    //fill up the hash map with counts of occurrences of characters in the string
    for (unsigned int i = 0; i < s.size(); i++) {
        umap[s[i]]++;

        //if the count is a pair, then add the letter to the vector
        if (umap[s[i]] % 2 == 0) {
            v.push_back(s[i]);
            //s[i] = '-';
        }
    }

    //check for validity of palindrome
    // 1. check if there is at most 1 count of letters in the map that is odd. 
    for (unsigned int i = 0; i < s.size(); i++) {

        //no solution if there is more than 1 odd count of letters
        if (num_odds > 1) {
            cout << "NO SOLUTION";
            return 0;
        }

        //if there is an odd count of letters, set it to the extra letter
        if (umap[s[i]] % 2 == 1) {
                umap[s[i]] = 2; //set to an even count so it doesn't count the same letter more than once
                num_odds++;
                extra_letter = s[i];
        }
    }

    //printing out the vector then reversing it
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    if (extra_letter != '-') cout << extra_letter; //if theres an extra letter

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }

    cout << endl;
}