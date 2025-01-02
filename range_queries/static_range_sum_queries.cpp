#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> range(n + 1, 0);

    // for each index, calculate the prefix sum
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        ll val;
        cin >> val;
        sum += val;
        range[i] = sum;
    }

    // the sum of the range is simply the higher end of the range subtracted by 
    // the lower end of the range
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << range[b] - range[a - 1] << '\n';
    }



    return 0;
}