#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll m;
    ll diff;
    ll count = 0;
    deque<int> desired;
    deque<int> available;

    cin >> n;
    cin >> m;
    cin >> diff;
    

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        desired.push_back(val);
    }	     

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        available.push_back(val);
    }

    // sort the arrays 
    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());

    ll cycle = 0;
    int i = 0;
    int j = 0;

    // if the desired size matches to an avaiable, increment the index
    while (i < desired.size() && j < available.size()) {
        if (abs(desired[i] - available[j]) <= diff) {
            count++;
            i++;
            j++;
        }
        
        // otherwise skip the lowest number, either from desired or the available
        // the lowest number is guaranteed to not match with anything
        else if (desired[i] > available[j]){
            j++;
        }
        else {
            i++;
        }
    }
    
    cout << count << endl;
    
}
