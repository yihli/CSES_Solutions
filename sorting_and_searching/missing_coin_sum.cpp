#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll x;
    vector<ll> coins;
    for (int i = 0; i < n; i++) {
        cin >> x;
        coins.push_back(x);
    }

    sort(coins.begin(), coins.end());

    // since the coins are sorted, the smallest n-size subsets are created by taking the first n 
    // values. if the sum of those n-size subsets does not equal the next coin value, then the 
    // next impossible value is the sum + 1.
    //
    // this operates on the fact that we start from 1 and increase, so if 2 can be made from the 
    // subset, then so can 3, then 4, and so on... as long as the sum keeps increasing by 1. 
    // if a coin sum is encountered that doesnt allow you to make the current sum + 1, then 
    // that value is not possible.

    ll sum = 0;
    for (unsigned int i = 0; i < coins.size(); i++) {
        if (sum + 1 < coins[i]) {
            break;
        }
        sum += coins[i];
    }
    cout << sum + 1 << endl;

}