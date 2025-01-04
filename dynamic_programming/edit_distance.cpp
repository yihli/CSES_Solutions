#include <bits/stdc++.h>

using namespace std;

int main() {
    // similar to LCS, we use a 2d array to store the edit distances, where dp[i][j]
    // is the edit distance up to first[i] and second[j]
    // [i - 1][j], [i - 1][j - 1], [i][j - 1] all correspond to an action, either 
    // insertion, deletion, or substitution. 
    // if the characters at a certain [i][j] do not match, we have to perform one
    // of those actions for a +1 edit distance. if they do match, we can simply take 
    // the [i - 1][j - 1] edit distance.
    string first;
    string second;
    int n, m;

    cin >> first >> second;
    n = first.length();
    m = second.length();

    // dp array
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // the first row and column edit distance is simply the length of the word 
    // because the edit distance to a blank string is the length.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // matching characters means we take the edit distance of the previous i and j.
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];

            // if not, we perform an action with +1. use the minimum of all other previous edit distances
            // to continue the algorithm with the least edit distance.
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}