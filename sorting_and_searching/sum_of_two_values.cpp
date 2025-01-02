#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    set<pair<int, int>> mp;
    set<pair<int, int>> mp_temp;
    int n, x, a;

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        mp.insert(make_pair(a, i));
    }

    // a copy of the set of pairs is made
    mp_temp = mp;

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {

        // preventing duplicates 
        mp_temp.erase(mp_temp.find(*iter));

        // finding the smallest value whose pair is equal to or greater than {difference, 0} 
        // and checking if the difference is the desired difference 
        if (mp_temp.lower_bound({x - iter->first, 0}) != mp_temp.end() && mp_temp.lower_bound({x - iter->first, 0})->first == x - iter->first) {
            cout << iter->second << " " << mp_temp.lower_bound({x - iter->first, 0})->second << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

}