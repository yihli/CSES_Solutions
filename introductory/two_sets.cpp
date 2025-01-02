#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    
    cin >> n;

    // if n is 3 mod 4, because the set {1, 2, 3} can be equally split,
    // and 4 is the inductive step of the proof.
    // inductive proof: (n + 1)(n + 4) = (n + 2)(n + 3)
    if (n % 4 == 3) {

        cout << "YES" << '\n';

        cout << (n / 2) + 1 << '\n';
        cout << 1 << " " << 2 << " ";

        //(n + 2)(n + 3)
        for (ll i = 3; i <= n - 4; i += 4) {
            cout << i + 2 << " " << i + 3 << endl;
        }

        cout << (n / 2) << '\n';
        cout << 3 << " ";

        //(n + 1)(n + 4)
        for (ll i = 3; i <= n - 4; i += 4) {
            cout << i + 1 << " " << i + 4 << " ";
        }
    }

    //if sum of sets is divisible by 2
    else if (n * (n + 1) / 2 % 2 == 0) {
        cout << "YES" << '\n';

        //size
        cout << n / 2 << '\n';

        //take first and last, first + 2, last - 2...
        for (ll i = 1; i <= n; i += 2) {
            cout << i << " ";

            //skips 3 in the middle
            if (i == (n / 2) - 1) {
                i += 1;
            }
        }

        //take first + 1 and last - 1, first + 3, last - 3...
        cout << '\n' << n/2 << '\n';
        for (ll i = 2; i <= n; i += 2) {
            cout << i << " ";

            //skips 1 in the middle
            if (i == n / 2) {
                i--;
            }
        }
    }
    else {
        cout << "NO" << endl;
    }

  
}