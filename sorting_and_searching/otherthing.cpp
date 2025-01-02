#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int>& temp, vector<int> nums) {
    if (temp.size() == nums.size()) {
        for (auto x : temp) {
            cout << x;
        }
        cout << endl;
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) continue;
            int temp_val = nums[i];
            nums[i] = -1;
            temp.push_back(temp_val);
            permute(temp, nums);
            temp.pop_back();
            nums[i] = temp_val;
        }
    }
}

void subsets(vector<int>& temp, vector<int> nums, int index) {
    cout << "{";
    for (auto x : temp) {
        cout << x;
    }
    cout << "}" << endl;

    for (int i = index; i < nums.size(); i++){
        temp.push_back(nums[i]);
        subsets(temp, nums, i + 1);
        temp.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<int> temp;

    cout << "Permutations: " << endl;
    permute(temp, nums);

    temp.clear();
    cout << "Subsets: " << endl;
    subsets(temp, nums, 0);
    
    
}