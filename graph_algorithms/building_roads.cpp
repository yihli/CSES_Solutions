#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

// adj list 
// track which cities are visited
// track which cities need to be linked
vector<vector<int>> adj;
vector<bool> visited;
vector<int> to_link;

// dfs visits every connected city until it cannot, marking them visited along the way
void dfs(int visiting) {
    visited[visiting] = true;
    for (int x : adj[visiting]) {
        if (visited[x] == false) {
            dfs(x);
        }
    }
}

int main() {
    // there will be multiple groups of cities that are already connected. 
    // use DFS to establish those groups. When we move on to a new node that
    // hasn't been part of a group, we know to link those.
    int n, m, a, b;
    cin >> n >> m;
    visited = vector<bool>(n + 1, false);
    adj = vector<vector<int>>(n + 1, vector<int>());

    // fill adj list
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // use dfs to visit cities, and each new instance of dfs we have to manually
    // initiate is a new road to build
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            to_link.push_back(i);
            dfs(i);
        }
    }

    // print out number of roads to build as well as the specific cities to connect
    cout << to_link.size() - 1 << endl;
    for (int i = 1; i < to_link.size(); i++) {
        cout << to_link[i - 1] << " " << to_link[i] << endl;
    }

    return 0;        
}