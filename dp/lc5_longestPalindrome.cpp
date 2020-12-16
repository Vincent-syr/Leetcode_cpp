#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 15:56:59
 * @LastEditTime: 2020-12-16 16:31:31
 * @Description: file content

https://leetcode-cn.com/problems/longest-palindromic-substring/
ref：https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484471&idx=1&sn=7c26d04a1f035770920d31377a1ebd42&chksm=9bd7fa3faca07329189e9e8b51e1a665166946b66b8e8978299ba96d5f2c0d3eafa7db08b681&scene=21#wechat_redirect
5. 最长回文子串 middle
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"


解答：
    可用非动态规划做，核心：双指针，palidrome是以l和r为中心向外扩张建立回文串，
    l=r时表示奇数一个中心，r=l+1时表示回文串是偶数，两个中心
复杂度：
    时间：O(N)
    空间: O(1)
debug点：
    subStr(int pos, int n) 是起始点和长度，不是python那样的左开右闭区间；

 */

    string palindrome(string& s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;    r++; // 中心向外扩大； 
        }
        if(l+1 > r-1)   return "";
        return s.substr(l+1, (r-1-l));
    }

    string longestPalindrome(string s) {
        string maxStr = "";
        for(int i=0; i<s.length(); i++){
            string curStr1, curStr2;
            curStr1 = palindrome(s, i, i);
            curStr2 = palindrome(s, i, i+1);  
            // update
            maxStr = curStr1.length() > maxStr.length()? curStr1: maxStr;
            maxStr = curStr2.length() > maxStr.length()? curStr2: maxStr;
        }

        return maxStr;
    }

    int main(int argc, char const *argv[]){
        string s = "babad";
        // cout<< s.substr(0,1)<<endl;
        cout<< longestPalindrome(s);
    }