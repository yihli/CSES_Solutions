#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> ranges;

    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y; 
        ranges.insert({x, y});
    }

    set<pair<int,int>>::iterator iter;

    for (iter = ranges.begin(); iter != ranges.end(); iter++) {
        
    }

    return 0;
}