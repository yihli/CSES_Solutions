#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    int temp = 0;
    int maxi = 0;
    map<int, int> map;

    cin >> n;

    // put arrival times and departure times into map
    // represents the entering and leaving at certain times
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        map[a]++;
        map[b]--;
    }

    // sum up the arriving and leaving and get the largest number
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        temp += iter->second;
        if (temp > maxi) {
            maxi = temp;
        }
    }

    cout << maxi << '\n';
}

