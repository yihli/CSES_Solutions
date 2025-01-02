//
// recursive solution
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    ll mod = (1e9 + 7);
    v[0] = 1;

    // for each value up to n
    // sum up the totals from before 
    // 0 1 2 3 4 5 6 7 8 9
    // 1 0 1 1 1 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                v[i] += v[i - j] % mod;
            }
        }
    }

    // remember to mod the final output if it hasnt been
    cout << v[n] % mod << endl;
}