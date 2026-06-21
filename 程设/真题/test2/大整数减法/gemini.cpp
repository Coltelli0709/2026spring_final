#include<bits/stdc++.h>
using namespace std;

// global variables
int t;
string a, b;
vector<int> res;

int main(){
    // speed up
    ios::sync_with_stdio(0); cin.tie(0);

    if(cin >> t){
        while(t--){
            // receive
            cin >> a >> b;
            res.clear();

            int len_a = a.size();
            int len_b = b.size();

            // reverse strings to align from the lowest digit
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());

            // process subtraction
            int borrow = 0;
            for(int i = 0; i < len_a; i++){
                int val_a = a[i] - '0';
                int val_b = (i < len_b) ? (b[i] - '0') : 0;

                int diff = val_a - val_b - borrow;
                if(diff < 0){
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                res.push_back(diff);
            }

            // pop leading zeros (which are trailing in the reversed result)
            while(res.size() > 1 && res.back() == 0){
                res.pop_back();
            }

            // output
            for(int i = res.size() - 1; i >= 0; i--){
                cout << res[i];
            }
            cout << "\n";
        }
    }
    return 0;
}