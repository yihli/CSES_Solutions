#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int n{}, m{};
    cin >> n >> m;

    vector<string> map;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    auto inside = [&](int row, int col) {
        return row >= 0 && row < map.size() && col >= 0 && col < map[0].size();
    };

    vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<string>> paths(n, vector<string>(m, ""));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'A') {
                queue<pair<int, int>> to_visit;
                to_visit.push({i,j});
                map[i][j] = '#';
                while (!to_visit.empty()) {
                    pair<int,int> p = to_visit.front();
                    to_visit.pop();
                    // cout << p.first << p.second << paths[p.first][p.second];

                    if (inside(p.first + 1, p.second) && 
                        map[p.first + 1][p.second] != '#') {
                        if (map[p.first + 1][p.second] == 'B') {
                            cout << "YES" << '\n';
                            cout << paths[p.first][p.second].size() + 1 << '\n';
                            cout << paths[p.first][p.second] + "D" << endl;
                            return 0;
                        }
                        map[p.first + 1][p.second] = '#';
                        to_visit.push({p.first + 1, p.second});
                        paths[p.first + 1][p.second] = paths[p.first][p.second] 
                        + "D";
                    }

                    if (inside(p.first, p.second + 1) && 
                        map[p.first][p.second + 1] != '#') {
                        if (map[p.first][p.second + 1] == 'B') {
                            cout << "YES" << '\n';
                            cout << paths[p.first][p.second].size() + 1 << '\n';
                            cout << paths[p.first][p.second] + "R" << endl;
                            return 0;
                        }
                        map[p.first][p.second + 1] = '#';
                        to_visit.push({p.first, p.second + 1});
                        paths[p.first][p.second + 1] = paths[p.first][p.second] 
                        + "R";
                    }

                    if (inside(p.first - 1, p.second) && 
                        map[p.first - 1][p.second] != '#') {
                        if (map[p.first - 1][p.second] == 'B') {
                            cout << "YES" << '\n';
                            cout << paths[p.first][p.second].size() + 1 << '\n';
                            cout << paths[p.first][p.second] + "U" << endl;
                            return 0;
                        }
                        map[p.first - 1][p.second] = '#';
                        to_visit.push({p.first - 1, p.second});
                        paths[p.first - 1][p.second] = paths[p.first][p.second] 
                        + "U";
                    }

                    if (inside(p.first, p.second - 1) && 
                        map[p.first][p.second - 1] != '#') {
                        if (map[p.first][p.second - 1] == 'B') {
                            cout << "YES" << '\n';
                            cout << paths[p.first][p.second].size() + 1 << '\n';
                            cout << paths[p.first][p.second] + "L" << endl;
                            return 0;
                        }
                        map[p.first][p.second - 1] = '#';
                        to_visit.push({p.first, p.second - 1});
                        paths[p.first][p.second - 1] = paths[p.first][p.second] 
                        + "L";
                    }

                    paths[p.first][p.second].clear();
                }
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}