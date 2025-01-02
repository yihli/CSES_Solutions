#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;

    cin >> n;

    for (ll i = 1; i <= n; i++) {

        // 1. calculate (n)(n + 1) / 2 for all possible positions and knights not swappable
        // 2. in each 2 x 3 rectangles, there are 2 ways for knights to attack each other. 
        //    there are (i - 1) * (i - 2) ways to put 2 x 3 rectangles, multiply that by 2 to put 2 x 3 rectangles.
        //    >> 2 (i - 1) (1 - 2)
        // 3. there are 2 ways in each of those rectangles to place knights that attack each other.
        //    >> 2 * 2 (i - 1) (i - 2)
        cout << ((i * i) * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2) << endl;
    }
}