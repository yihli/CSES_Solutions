#include <string>
#include <iostream>
typedef long long ll;
using namespace std;

int main () {
    string string;
    getline(cin, string);
    char curr_c = string.at(0);
    int max = 0;
    int max_cand = 0;

    for (int i = 0; i < string.size(); i++) {

        // count the current subsequence of same characters
        if (curr_c == string.at(i)) {
            max_cand++;
        }

        // change the letter and reset count if found a new character
        else {
            curr_c = string.at(i);
            max_cand = 1;
        }
        
        // check if the just counted subsequence is the longest one so far
        if (max_cand > max) {
            max = max_cand;
        }
    }

    cout << max << '\n';
}