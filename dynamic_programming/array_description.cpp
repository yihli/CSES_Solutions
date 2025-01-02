#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
    int n, m, value;
    cin >> n >> m;

    // 2D array where dp[i][j] represents the number of ways you can reach the 
    // value j at the ith value of the given values.
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // if the first input is 0, then there is one way to reach all possible values
    // if the first input is not zero, then there is only one way to reach that input
    // and all other values have zero ways.
    cin >> value;
    if (value == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else if (value > 0) {
        dp[0][value] = 1;
    }

    // fill the dp array in order to check how many ways there are to reach each 
    // new input value
    for (int i = 1; i < n; i++) {
        cin >> value;

        // if the input is a fixed value, we add up the ways to obtain the input given the ways
        // from the previous values. 

        // For example, given the value 3 as the 5th value, the number of ways to reach 3
        // would be the sum of the # ways to have 2,3,4 as the 4th value of the array
        if (value > 0) {
            if (value + 1 <= m) {
                dp[i][value] = (dp[i][value] + dp[i - 1][value + 1]) % MOD;
            }

            if (value - 1 >= 1) {
                dp[i][value] = (dp[i][value] + dp[i - 1][value - 1]) % MOD;
            }

            dp[i][value] = (dp[i][value] + dp[i - 1][value]) % MOD;

        // If the input value is 0, it can be anything and therefore we must traverse
        // all possible values to see how many ways there are to contain each value
        } else if (value == 0) {
            for (int j = 1; j <= dp[0].size(); j++) {
                if (j + 1 <= m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }

                if (j - 1 >= 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }

                dp[i][j] = (dp[i][j]  + dp[i - 1][j]) % MOD;
            }
        }
    }

    // the results are the sum of all the ways to make arrays at the last input value. 
    int result = 0;
    for (int i : dp[dp.size() - 1]) {
        result = (result % MOD + i % MOD) % MOD;
    }

    cout << result;

    return 0;
}