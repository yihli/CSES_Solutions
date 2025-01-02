#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;



int main() {
    ll n;
    cin >> n;

    if (n < 2 || n > 3) {

        //simply print the even numbers then print the odd numbers.
        for (int i = 2; i <= n; i = i + 2) {
            cout << i << " ";
        }

        for (int i = 1; i <= n; i = i + 2) {
            cout << i << " ";
        }
    }

    // cannot be {1, 2}, {1, 2, 3}
    else {
        cout << "NO SOLUTION";
    }
}