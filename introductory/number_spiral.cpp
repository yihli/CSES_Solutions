#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll y, x; //y is row, x is col
    ll t; //num tests

    cin >> t;

    for (ll i = 0; i < t; i++) {
        cin >> y >> x;

        if (y > x) {
            if (y % 2 == 1) {
                cout << (y - 1) * (y - 1) + (x) << '\n';
            }
            else {
                cout << (y) * (y) - (x - 1) << '\n';
            }
        }
        else if (x > y) {
            if (x % 2 == 1) {
                cout << (x * x) - (y - 1) << '\n';
            }
            else {
                cout << (x - 1) * (x - 1) + y << '\n';
            }
        }
        else {
            cout << (y * y) - (y - 1) << '\n';
        }
    }
}