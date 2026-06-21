#include<bits/stdc++.h>
using namespace std;

//global variebles
string s;
int len, dot_pos; 
long long it, nu, de; 

//char转平衡三进制权值
int val(char c){
    if(c == '2') return -1;
    return (c - '0');
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    len = s.size();

    // 1. 找到小数点位置
    dot_pos = -1;
    for(int i = 0; i < len; i++) {
        if(s[i] == '.') { dot_pos = i; break; }
    }

    // 2. 统一计算分子 nu (将 s 看作没有小数点的整数)
    nu = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        nu = nu * 3 + val(s[i]);
    }

    // 3. 计算分母 de (根据小数点后的位数计算 3^k)
    de = 1;
    if(dot_pos != -1) {
        int k = len - 1 - dot_pos;
        for(int i = 0; i < k; i++) de *= 3;
    }

    // 4. 约分
    long long t = gcd(abs(nu), de);
    nu /= t; de /= t;

    // 5. 计算带分数部分
    it = nu / de;
    long long rem = abs(nu % de);

    // 6. 输出逻辑 (处理三种形态)
    if(rem == 0) {
        cout << it << endl;
    } else if(it == 0) {
        // 真分数情况：如果是负数，直接输出 nu de 即可，例如 -1 3
        cout << nu << " " << de << endl;
    } else {
        // 带分数情况：A B C
        cout << it << " " << rem << " " << de << endl;
    }
}

/* #include<bits/stdc++.h>
using namespace std;

//global variebles
string s;
int len, dot, t; //length, dot, temp
long long it, nu, de; //integer, numerator, denominator


//char转平衡三进制权值
int val(char c){
    if(c == '2') return -1;
    return (c - '0');
}

int main(){
    //speed up
    ios::sync_with_stdio(0);
    cin.tie(0);

    //receive
    cin>>s;
    len = s.size();

    dot = len; //if it's an integer
    nu = 0;

    //traverse
    for(int i = 0; i<len; i++){
        if(s[i] == '.') {dot = i; continue;}
        nu *= 3; nu += val(s[i]);
    }

    //process
    if(dot == len) {cout<<nu; return 0;} //if integer
    dot = len - 1 - dot;
    de = (dot%2) ? 3 : 1;
    dot /= 2;
    while(dot--){
        de *= 9;
    }

    //gcd
    t = gcd(nu, de);
    nu /= t; de /= t;
    it = nu/de;
    if(nu < 0) nu = -nu;

    //output
    cout<<it<<" "<<nu<<" "<<de;
}
*/
