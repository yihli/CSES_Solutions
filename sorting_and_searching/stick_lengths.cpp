#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ll n, p;
    ll median = 0;
    ll cost = 0;
    cin >> n;
    vector<ll> v;

    for (int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    // use median because median takes into account the weight of each side
    // gets rid of effects of outliers.
    median = v[v.size() / 2];
    

    for (auto x : v) {
        cost += abs(x - median);
    }

    cout << cost << endl;
    
}