#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ll t;
    ll a, b;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        cin >> a >> b;

        //the totals of the coin pile must be 0 mod 3
        if ((a + b) % 3 == 0) {

            //the ratio of coins must not be greater than 2:1
            if (min(a,b) * 2 >= max(a,b)) {
                cout << "YES" << '\n';
                continue;
            }

        }
        cout << "NO" << '\n';
    
    }
}