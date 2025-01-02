#include <iostream>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n{}, m{};
    cin >> n >> m;

    char map[n][m];
    pair<int,int> start;
    pair<int,int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') start = {i, j};
            if (map[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<int>> previous(n, vector<int>(m, 9));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    string direction = "RDLU";

    queue<pair<int,int>> to_visit;
    to_visit.push(start);
    visited[start.first][start.second] = 1;
    while (!to_visit.empty()) {
        pair<int,int> p = to_visit.front();
        to_visit.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = p.first + dy[i];
            int new_col = p.second + dx[i];
            if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue;
            if (visited[new_row][new_col]) continue;
            if (map[new_row][new_col] == '#') continue;

            to_visit.push({new_row, new_col});
            visited[new_row][new_col] = 1;
            previous[new_row][new_col] = i;
        }
    }

    if (visited[end.first][end.second]) {
        cout << "YES" << '\n';
        
        vector<char> path;
        while (end != start) {
            path.push_back(direction[previous[end.first][end.second]]);
            end = {end.first - dy[previous[end.first][end.second]], end.second - dx[previous[end.first][end.second]]};
        }
        cout << path.size() << '\n';
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
        }
    }
    else {
        cout << "NO" << '\n';
    }
}