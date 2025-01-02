#include <iostream>

typedef long long ll;
using namespace std;

ll summate(ll n) {
    return (n * (n+1))/2;
}

int main() {
    ll n = 0;
    ll sum = 0;

    cin >> n;

    // get the total of the numbers
    for (ll i = 0; i < n - 1; i++) {
        ll x;
        cin >> x;
        sum += x;
    }

    // subtract the sum from the actual total to get the missing number
    cout << summate(n) - sum << '\n';

}