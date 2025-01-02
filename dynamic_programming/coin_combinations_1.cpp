#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> coins;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        coins.push_back(c);
        // dp[i] = 1;
    }

    for (int i = 1; i <= x; i++) {
        for (ll coin : coins) {
            if (i - coin >= 0)
            dp[i] += dp[i - coin] % 1000000007;
        }
    }

    cout << dp[x] % 1000000007;

}