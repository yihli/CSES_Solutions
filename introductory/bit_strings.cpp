#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // The number of binary strings of length n is 2^n.
    // Howver to express as modulo, we have to start off with
    // 2 mod MAX 
    // 2 * 2 mod MAX (2 mod MAX * 2 mod MAX) mod MAX
    // 2 * 2 * 2 mod MAX (2 mod MAX * 2 mod MAX * 2 mod MAX) mod MAX
    //
    // i.e: 2^5 mod MAX can be split in 2 * 2 * 2 * 2 * 2 which is (2 mod MAX) * (2 mod MAX) ...
    // using a modular property

    ll n;
    ll value = 1;

    cin >> n;
    

    while(n > 0) {
        value = (value * 2) % 1000000007;
        n--;
    }

    cout << value << endl;
}