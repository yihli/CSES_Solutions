#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, t;
    multiset<int> prices;

    cin >> n >> m;

    // insert elements into multiset. multiset sorts elements automatically.
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        prices.insert(h);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        
        // upper bound searches for the smallest element above the specified. 
        auto iter = prices.upper_bound(t);
        
        // if the largest is the smallest thing in the set, then there are no more tickets.
        if (iter == prices.begin()) {
            cout << -1 << '\n';
        }
        else {
            
            // decrement iter to get the ticket just before the upper bound
            // if upper bound exists, that means the ticket before can be bought
            cout << *(--iter) << '\n';
            prices.erase(iter);
        }
    }
}