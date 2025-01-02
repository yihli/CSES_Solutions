#include <bits/stdc++.h>

using namespace std;

int main() {
    // Use BFS to count and update shortest distances from node 1 to every other node.
    // Mark visited nodes. 
    // If a node's distance has to be updated, then there is a shorter path 
    // to that node. Update the pi array to show what previous node creates
    // a shorter path.
    // The distance to computer n is how many computers are in the minimum path. 
    // Follow the pi array to trace back the route.
    int n, m, a, b;

    cin >> n >> m;

    // adjacency list, distance and pi arrays
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> distances(n + 1, 999999);
    vector<int> pi(n + 1, 0);
    distances[1] = 1;       // distance from computer 1 to 1

    // fill the adj list
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // use queue for BFS
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        // get node to visit
        int current = q.front();
        q.pop();

        for (int x : adj[current]) {

            // if adjacent node unvisited, add to BFS
            if (distances[x] == 999999) {
                q.push(x);
            }

            // if adjacent node's distance is shortened by the current, update it 
            // and the pi array.
            if (distances[current] + 1 < distances[x]) {
                distances[x] = distances[current] + 1;
                pi[x] = current;
            }
        }
    }
    
    // no previous node for n means unreachable
    if (pi[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // trace back. need to reverse the output using vector
    cout << distances[n] << endl;
    int current = n;
    vector<int> v;
    for (int i = 0; i < distances[n]; i++) {
        v.push_back(current);
        current = pi[current];
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }


    return 0;
}