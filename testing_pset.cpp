#include <bits/stdc++.h>
using namespace std;

// void pset(vector<vector<int>>& subsets, vector<int>& nums, int index, vector<int>& temp) {
//     subsets.push_back(temp);

//     for (int i = index; i < nums.size(); i++) {
//         temp.push_back(nums[i]);
//         pset(subsets, nums, i + 1, temp);
//         temp.pop_back();
//     }
// }




int main() {
    deque<deque<int>> subsets = {};
    deque<int> nums = {1,2,3};
    vector<int> temp = {};

    pset(subsets, nums, nums.size() - 1);

    for (deque<int> v : subsets) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}