#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    int n{};
    cin >> n;  
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // brute force: vector of top tower block sizes. if an input is smaller than one of them, 
    // replace that with the smaller one. otherwise, create a new tower in the vector.
    /*
    ll val{};
    vector<ll> towers(1,9999999999);
    for (int i = 0; i < n; i++) {
        cin >> val;

        for (int j = 0; j < towers.size(); j++) {
            if (val < towers[j]) {
                towers[j] = val;
                break;
            }

            if (j == towers.size() - 1) {
                towers.push_back(val);
                break;
            }
        }
    }
    cout << towers.size() << endl;
    */

    // idea 1: using a multiset to store the weights of the top blocks of each tower. 
    // for each input, see if there is a smallest weight it can stack on top of, otherwise 
    // it starts a new tower.

    ll val{};
    
    // multiset allows for multiple towers with similar top sizes.
    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        cin >> val;

        // find the next largest weight on a tower.
        set<int>::iterator next_largest = towers.upper_bound(val);

        // if no such weight exists, we must start a new tower. 
        if (next_largest == towers.end()) {
            towers.insert(val);

        // if such a weight exists, replace that weight with the input's weight.
        } else {
            towers.erase(next_largest);
            towers.insert(val);
        }
    }
    cout << towers.size();
}