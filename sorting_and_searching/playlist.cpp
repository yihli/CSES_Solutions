#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n{};
    cin >> n;

    // idea 1: use a set because sets don't allow duplicates
    //
    /*
    set<int> id;
    for (int i = 0; i < n; i++) {
        int k{ };
        cin >> k;

        id.insert(k);
    }

    cout << id.size() << '\n';
    */

    // idea 2: use a map and check if the value after exists. 
    // should be longest successive subsequence as given by input
    /*
    map<int,int> id;
    for (int i = 0; i < n; i++) {
        int k{ };
        cin >> k;
        
        id[k] = 1;
    }

    int count{ 1 };
    int highest{ 0 };
    for (auto iter : id) {
        // map initializes key, value if it never existed before.
        if (id[iter.first - 1] == 1) {
            count++;
            highest = max(highest, count);
        } else {
            count = 1;
        }
    }
    */

    // idea 3: use a map to remember if a number has been used. if it has been used before,
    //         decrement the length.
    //  does not account for space in between sequences
    /*
    map<int, int> id;
    int length{0};
    int dist_from_last{0};
    int max{0};
    for (int i = 0; i < n; i++) {
        int k{ };
        cin >> k;
        
        id[k]++;
        if (id[k] != 0) {
            id[k]--;
        }

    }
    */

    // idea 4: sliding window with two pointers and a set to track.
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int val{};
        cin >> val;
        v.push_back(val);
    }

    int right{0};
    int left{0};
    int length{0};
    set<int> s;
    while (right < n) {
        // while a number has no been used yet, add that number to the used and increase the right.
        // 1 2 1 3 2 7 4 2
        while (right < n && !s.count(v[right])) {
            s.insert(v[right]);
            right++;
        }

        // once a number has been to detected to have been used, we update the max length
        // v   v r             
        // 1 2 1 3 2 7 4 2  length: 2 - 0 = 2
        length = max(length, right - left );

        // move the left point and remove numbers until the number found by the right point
        // is removed.
        //     l---->l   r
        // 1 2 1 3 2 7 4 2
        while (left < n && s.count(v[right])) {
            s.erase(v[left]);
            left++;
        }
    }

    cout << length << endl;
    return 0;
}