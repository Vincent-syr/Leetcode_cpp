#include <iostream>
#include <string>
using namespace std;


/* 
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

解法：
    相当于在数组中多次插入元素，从后往前插入，可减少时间复杂度；如果从前往后插入，则时间负责度O(n*m),
    其中n是s长度，m是插入次数；
注意：
    string类的结尾是'\0'，需要注意？；
    
 */

    string replaceSpace(string s) {
        int rawLen = s.size();
        if(s.size()==0) return s;
        int cnt = 0;
        for(auto &c: s){
            if(c==' ')  cnt++;
        }
        s.resize(s.size() + 2*cnt);  // string的末尾是'\0'
        for(int i=rawLen; i>=0; i--){
            if(s[i] == ' '){
                s[i+2*cnt] = '0';
                s[i+2*cnt-1] = '2';
                s[i+2*cnt-2] = '%';
                cnt--;
                continue;
            }

            s[i+2*cnt] = s[i];
        }
        cout<< s<< "   "<<s.size();
        return s;
        // cout<< cnt;
    }

    int main(int argc, char const *argv[])
    {
        string s = " ceaa e";
        // cout << s.size()<<endl;
        // cout<< s[13];
        replaceSpace(s);
        return 0;
    }
    