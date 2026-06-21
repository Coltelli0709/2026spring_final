#include <bits/stdc++.h>
using namespace std;

//BigInt：除以2、乘以2、加法
struct BigInt {
    vector<int> d; 
    
    BigInt(string s) { 
        for(int i = s.size() - 1; i >= 0; i--) d.push_back(s[i] - '0'); 
    }
    
    BigInt(int v = 0) { 
        if(v == 0) d.push_back(0);
        while(v > 0) { d.push_back(v % 10); v /= 10; }
    }
    
    bool isZero() {
        return d.empty() || (d.size() == 1 && d[0] == 0);
    }
    
    //1. 除2取余
    int div2() {
        int rem = 0;
        for(int i = d.size() - 1; i >= 0; i--) {
            int cur = d[i] + rem * 10;
            d[i] = cur / 2;
            rem = cur % 2;
        }
        while(d.size() > 1 && d.back() == 0) d.pop_back();
        return rem;
    }
    
    //2. 乘2加1
    void mul2add(int b) {
        int carry = b;
        for(int i = 0; i < d.size() || carry; i++) {
            if(i == d.size()) d.push_back(0);
            int cur = d[i] * 2 + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
    }
    
    void print() {
        for(int i = d.size() - 1; i >= 0; i--) cout << d[i];
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; 
    if(!(cin >> t)) return 0;
    
    for(int k = 0; k < t; k++) {
        string s; 
        cin >> s;
        
        cout << "case #" << k << ":" << endl;
        
        //if：输入为 0
        if(s == "0") {
            cout << 0 << endl;
            continue;
        }
        
        BigInt n(s);
        string rev_bin = "";
        
        /*
        由于 div2() 是从最低位开始取余
        所以拼接出来的字符串天然就是倒置后的二进制形式，无需 reverse！
        */

        while(!n.isZero()) {
            rev_bin += (char)('0' + n.div2());
        }
        
        //3. 转回十进制
        BigInt res(0);
        for(char c : rev_bin) {
            res.mul2add(c - '0');
        }
        
        res.print();
    }
    
    return 0;
}