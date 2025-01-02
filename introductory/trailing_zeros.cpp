#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    /*
    The number of trailing zeroes is the number of times n can be divided by 10. 
    The prime factorization of 10 is 5 and 2. There are more 5's than 2's.
    We will calculate how many 5's are in n, 25's in n (with each adding 1 more 5), 
    and so on.
    */

    ll n;
    ll M;
    ll trailing = 0;

    cin >> n;
    
    //goes up to 5^M, where 5^M is the largest power of 5 that is less than n.
    M = log(n) / log(5);
    
    for (int i = 1; i <= M; i++) {
        trailing += (n / pow(5, i));
    }

    cout << trailing << endl;
 }