#include <bits/stdc++.h>
using namespace std;

int numOdd;
int freq[26];
deque<char> ans;
char odd = '9';
string s;

int main(){
    cin >> s;
    for(int i = 0; i < (int)s.length(); i++){
        freq[s[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] % 2){
            numOdd++;
            odd = (char) ('A' + i);
        }
    }

    if(numOdd > 1){
        cout << "NO SOLUTION\n";
    }
    else{
        if(numOdd) ans.push_back(odd);
        for(int i = 0; i < 26; i++){

            for(int j = 0; j < freq[i]/2; j++){
                ans.push_front(i + 'A');
                ans.push_back(i + 'A');
            }
        }

        for(int i = 0; i < (int) ans.size(); i++){
            cout << ans[i];
        }
        cout << endl;
       
    }

     

}