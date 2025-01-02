#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n, x, c;
    cin >> n >> x;
    vector<ll> v(x+1,1e9);
    vector<ll> coins;

    // set the zeroeth index to 1
    v[0] = 1;

    // adding coin values to list of coins
    for (int i = 0; i < n; i++) {
        cin >> c;
        coins.push_back(c);
        if (c <= x) v[c] = 1;
    }

    // find all the possible number of coins to make the current sum, and take the minimum each time.
    // the resulting value at index i equals the least amount of coins needed.
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                v[i] = min(v[i], 1 + v[i-c]);
            }
        }
    }

    // if the value at index x is the default value that means it was impossible to make the sum
    if (v[x] == 1e9) cout << -1 << endl;
    else cout << v[x] << endl;

    
}