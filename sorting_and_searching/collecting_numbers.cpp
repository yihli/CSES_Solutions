#include <iostream>
#include <map>

using namespace std;

int main () {
    int n{};
    cin >> n;

    // idea 1: count how many numbers until we reach 1
    // does not work for 5 4 2 3 1 
    /*
    int count{0};
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        count++;
        if (x == 1) break;
    }
    */

    // idea 2: same thing as idea 1 but if an x is larger than the current min we don't
    //         add to the count
    // does not work for something like 23 2300 2400 24 50 100 1
    /*
    int count{0};
    int curr_min{100000000};
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;

        if (x < curr_min) {
            curr_min = x;
            count++;
        }  
        if (x == 1) break;
    }
    */

    // idea 3: remember the maximum value until we reach something smaller, at which point we 
    //         increase count by one and start counting again, until we reach 1
    /*
    int count{1};
    int max{0};
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;

        if (x > max) {
            max = x;
        } else {
            count++;
            max = x;
        }

        // if (x == 1) break;
    }
    */

    // idea 4: use a map to store indices. the key is the value and the value is the index
    //         this works because the numbers are from 1 to n in increasing order.
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        int x{};
        cin >> x;
        m[x] = i;
    }

    // if the next value's index is before the current value's index, then that is the end of 
    // the round
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (m[i + 1] < m[i]) {
            count++;
        }
    }

    cout << count << endl;

}