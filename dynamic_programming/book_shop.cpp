#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);
    vector<bool> bought(n, false);
    vector<int> dp(x + 1, 0);

    // save the corresponding prices and pages
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    // for each book, check if we can buy it. 
    // for that budget amount, the max pages will either be the current max pages 
    // or a combination of the pages of the book we are buying plus the extra pages 
    // from books bought with the remaining amount.

    for (int book = 0; book < n; book++) {
        for (int budget = x; budget >= 0; budget--) {
            if (budget - price[book] >= 0) {
                dp[budget] = max(dp[budget], dp[budget - price[book]] + pages[book]);
            }
        }
    }

    // for (auto x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}