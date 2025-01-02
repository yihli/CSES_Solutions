#include <iostream>
#include <queue>
#include <string>

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


    // Using Breadth-First Search
    // Look through the map, finding a '.'. From there, we will look up, down,
    // left, and right, adding the positions of '.' to a queue. Then we will 
    // go to the next position in the queue to do the same thing. We keep doing 
    // it until the queue is empty, that's when the entire room is cleared.
    int num_rooms{0};

    // vector of directions to go in
    vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    // lambda function to make sure positions are not outside the map.
    auto inside = [&](int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    };

    // check the map until it encounters a '.'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // found the start to a new room
            if (map[i][j] == '.') {

                // queue to memorize the locations to visit
                queue<pair<int,int>> to_visit;
                to_visit.push({i, j});

                // must set the current '.' to a '#' so it isn't visited again
                map[i][j] = '#';

                // keep going while the queue has locations in it
                while (!to_visit.empty()) {

                    // using temporary pair so the location at the front of 
                    // queue can be popped
                    pair<int,int> p = to_visit.front();
                    to_visit.pop();

                    // checking in all directions
                    for (auto direction : directions) {
                        int new_row = p.first + direction.first;
                        int new_col = p.second + direction.second;

                        // if a direction contains a '.', add that location to 
                        // the queue and set it to '#'
                        if (inside(new_row, new_col) 
                            && map[new_row][new_col] == '.') {
                            to_visit.push({new_row, new_col});
                            map[new_row][new_col] = '#';
                        }
                    }
                }

                // after all connected '.' have been cleared, 
                num_rooms++;
            }
        }
    }

    cout << num_rooms << endl;

}