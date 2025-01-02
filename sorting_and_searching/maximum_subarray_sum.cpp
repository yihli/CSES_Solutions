#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
    ll n, x;

    cin >> n;
    cin >> x;

    ll best = x, sum = x;

    // two possibilities:
    // 1. the sum of the array up to x - 1 plus array[x].
    // 2. the value of array[x].
    //
    // check which of the two are larger, that will become the new sum
    // -> if sum plus array[x] is larger, the subsequence is still increasing.
    //      ->i.e 2 + 5 + ...  will always be larger than just 5 + ...
    //
    // -> if array[x] is larger, the new highest sum should be array[x]
    //      -> i.e -2 + 5 + ... will never be larger than just 5 + ...
    //
    // then compare if the current sum is larger than the current largest sum.

    for (int i = 1; i < n; i++) {
        cin >> x;
        sum = max(x, sum + x);
        best = max(best, sum);
    }

    cout << best << '\n';
}