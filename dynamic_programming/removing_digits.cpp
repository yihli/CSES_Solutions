#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
#define MAX_INPUT 10e7
 
int main() {
 
    int n;
    cin >> n;
 
    vector<int> dp(n + 1, MAX_INPUT);

    // we start at 0 moves for the original value
    dp[n] = 0;
 
    for (int i = n; i >= 0; i--) {

        // need to turn current value into string to get its individual digits
        string number = to_string(i);

        // for each individual digit
        for (unsigned int j = 0; j < number.size(); j++) {

            // number of moves to that new value is either:
            // 1. the current calculation of moves (moves to current value + 1)
            // 2. the already calculated number of moves to the new value
            dp[i - (number[j] - '0')] = min(dp[i] + 1, dp[i - (number[j] - '0')]);
        
        }
    }
 
    cout << dp[0];
 
 
 
 
    return 0;
}