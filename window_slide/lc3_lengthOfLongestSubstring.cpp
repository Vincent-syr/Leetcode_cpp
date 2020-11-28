#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

/* 
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成


框架：
    int left = 0, right = 0;

    while (right < s.size()) {
        window.add(s[right]);
        right++;
        
        while (有重复)) {
            window.remove(s[left]);
            left++;
        }
}

重点：
    重复一定是出现在新的hi，所以标记有无重复while(window[c1] > 1)；

 */


    int lengthOfLongestSubstring(string s) {
        int lo = 0, hi = 0, maxLen = 0;
        unordered_map<char, int> window;
        while(hi < s.size()){
            char c1 = s[hi];
            window[c1]++;
            while(window[c1] > 1){
                char c2 = s[lo];
                window[c2]--;
                lo++;    // move left
            }
            maxLen = max(maxLen, hi - lo + 1);
            hi++;   //move ri
        }
        return maxLen;
    }


    int main(int argc, char const *argv[])
    {
        string s = "abcabcbb";
        cout<< lengthOfLongestSubstring(s);
        return 0;
    }
    