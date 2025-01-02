#include <set>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    set<int> s = {}; // set does not allow duplicate numbers
    cin >> n;

    // input elements in set. set prevents adding duplicates
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        s.insert(val);
    }

    // size of set is the number of distinct values
    cout << s.size() << endl;
}