#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <stdlib.h>
using namespace std;
typedef long long ll;

void calc_subsets(vector<vector<ll>>& subsets, vector<ll> nums, vector<ll>& temp, ll index) {
    subsets.push_back(temp);

    for (ll i = index; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        calc_subsets(subsets, nums, temp, i + 1);
        temp.pop_back();
    }
}

ll sum(vector<ll>& v) {
    ll sum = 0;

    for (ll i : v) {
        sum += i;
    }

    return sum;
}

// Idea: Brute force calculate all the differences and see which one is the lowest.
// 1. Get vector from input.
// 2. Calculate all possible subsets and calculate the difference from there.
// 3. Choose the smallest difference

int main() {
    ll n;
    ll min_difference = 10e9;
    vector<vector<ll>> subsets;
    vector<ll> temp = {};
    vector<ll> nums;
    
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        nums.push_back(num);
    }

    calc_subsets(subsets, nums, temp, 0);

    
    ll total_sum = sum(nums);
    for (vector<ll> v : subsets) {
        ll sub_sum = sum(v);
        ll difference = abs((total_sum - sub_sum) - sub_sum);

        if (difference < min_difference) {
            min_difference = difference;
        }
    }

    cout << min_difference << endl;
}