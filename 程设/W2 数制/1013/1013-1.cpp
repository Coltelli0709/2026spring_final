#include<bits/stdc++.h>
using namespace std;
/* idea：
1. get string
2. 找小数点
3. 算double
4. 转带分数
*/

//注：s长度可以到三十，最好写一个快速幂

//global variebles
string s;
int sz, p;

//main function
int main(){
    //1. get string
    cin>>s;
    sz = s.size();

    //2. 找小数点
    for(int i = 0; i<sz; i++){
        if(s[i] == '.'){p = i; break;}
    }

    //3. 算double
}