#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int x;
    int num_gondolas = 0;
    vector<int> d = {};

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        d.push_back(val);
    }

    sort(d.begin(), d.end());

    // two pointer solution
    // initial solution with for loop didn't work
    // pairing up the smallest weights with the highest possible weight
    int i = 0;
    int j = d.size() - 1;
    while (i <= j) {
        if (d[i] + d[j] > x) {
            num_gondolas++;
            j--;
        }
        else {
            num_gondolas++;
            i++;
            j--;
        }
    }

    cout << num_gondolas << endl;
}