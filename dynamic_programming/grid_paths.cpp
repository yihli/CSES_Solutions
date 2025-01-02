#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    const int mod = 1e9 + 7;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;
    

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }

    auto inside = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    };

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            if (grid[i][j] == '*') {
                continue;
            }

            if (inside(i - 1, j)) dp[i][j] += dp[i - 1][j] % mod;
            if (inside(i, j - 1)) dp[i][j] += dp[i][j - 1] % mod;
        }
    }

    cout << dp[n - 1][n - 1] % mod;

    return 0;
}

    // Too slow: Use bfs to find all paths and sum it up
    // queue<pair<int, int>> to_visit;
    // to_visit.push({0, 0});
    // vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
    // while (!to_visit.empty()) {
    //     pair<int, int> next_square = to_visit.front();
    //     to_visit.pop();
    //     paths[next_square.first][next_square.second]++;

    //     for (auto direction : directions) {
    //         int new_i = next_square.first + direction.first;
    //         int new_j = next_square.second + direction.second;
    //         if (inside(new_i, new_j) && grid[new_i][new_j] == '.') {
    //             to_visit.push({new_i, new_j});
    //         }
    //     }
        

    // }