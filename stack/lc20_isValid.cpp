#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-04 22:24:05
 * @LastEditTime: 2020-12-04 22:38:13
 * @Description: file content
 * 
https://leetcode-cn.com/problems/valid-parentheses/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
20. 有效的括号  easy
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

解法：  耗时：10分钟
    不匹配的集中情况：
        1） 指向')', 但栈中为空；
        2） 指向')'，但栈首元素不匹配；
        3） for循环结束，栈中仍有元素，如"(()((";
 */


    bool isValid(string s) {
        bool res = true;
        stack<char> stk;
        unordered_map<char, char> map;
        map[')'] = '('; map[']'] = '['; map['}'] = '{';
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }   
            else{
                // stack空
                if(stk.empty()){
                    res = false; 
                    break;
                }
                // 不匹配
                if(stk.top() != map[s[i]]){
                    res = false;
                    break;
                }
                // 匹配
                else    stk.pop();
            }
        }
        // 检查stk中是否还有剩余元素
        if(! stk.empty())   res = false;
        return res;
    }

    int main(int argc, char const *argv[])
    {
        string s = "()[]{}";
        cout<< isValid(s);
        return 0;
    }
    