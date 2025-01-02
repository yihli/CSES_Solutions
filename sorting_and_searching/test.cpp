#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, n;
    cin >> x >> n;

    set<int> light_positions = {0, x};
    multiset<int> distances = {x};

    while (n--) {
        int new_position;
        cin >> new_position;

        light_positions.insert(new_position);

        // upper lower bound returns iterator. must dereference
        int next = *(light_positions.upper_bound(new_position));
        int prev = *(--light_positions.lower_bound(new_position));
        
        auto del = distances.find(next - prev);
        distances.erase(del);

        distances.insert(next - new_position);
        distances.insert(new_position - prev);

        cout << *(--distances.end()) << '\n';
    }
}