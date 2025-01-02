#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int coin : coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin >= 0) {
                dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
            }
        }
    }

    // for (int x : dp) {
    //     cout << x << " ";
    // }

    cout << dp[x] % 1000000007;


}