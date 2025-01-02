#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    vector<string> v = {" "};
    cin >> n;

    // a gray code is generated by mirroring existing strings 
    // and then adding 0 to the first half, then 1 to the second half
    while (n--) {
        //mirror the strings
        // 0 --> 0
        // 1     1
        //       1
        //       0
        for (int i = v.size() - 1; i >= 0; i--) {
            v.push_back(v[i]);
        }

        //add 0 to half the strings, 1 to the second half.
        for (int i = 0; i < v.size(); i++) {
            if (i < v.size() / 2) {
                string s = "0" + v[i];
                v[i] = s;
            }
            else {
                string s = "1" + v[i];
                v[i] = s;
            }
        }
    }

    //print the strings
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}
