#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

/*
https://leetcode-cn.com/problems/minimum-window-substring/
 76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

暴力解法：
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
            if s[i:j] 包含 t 的所有字母:
                更新答案

滑动窗口伪代码：
    string s, t;
    // 在 s 中寻找 t 的「最小覆盖子串」
    int left = 0, right = 0;
    string res = s;

    while(right < s.size()) {
        window.add(s[right]);
        right++;
        // 如果符合要求，移动 left 缩小窗口
        while (window 符合要求) {
            // 如果这个窗口的子串更短，则更新 res
            res = minLen(res, window);
            window.remove(s[left]);
            left++;
        }
    }
    return res;

复杂度分析：
    时间复杂度：O(M + N)；M 和 N 分别是字符串 s 和 t 的长度
    空间复杂度：O(N)
 */

    string minWindow(string s, string t) {
        int lo = 0, hi = 0;
        int start = 0, minLen = INT_MAX;   // start用于标记返回的起始点
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        
        for (char c : t) needs[c]++;

        // 记录 window 中已经有多少字符符合要求了
        int match = 0; 

        while(hi < s.size()){
            char c1 = s[hi];
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1] == needs[c1]) match++;
            }
            hi++;

            // 满足时移动lo 指针
            while(match == needs.size()){
                if(hi - lo < minLen){
                    // update minLen
                    start = lo;
                    minLen = hi - lo;
                }
                char c2 = s[lo];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2] < needs[c2])  match--;
                }
                lo++;
            }
        }
        if(minLen == INT_MAX)   return "";
        else    return s.substr(start, minLen);
    }

int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "BANC";
    cout << minWindow(s, t);
    return 0;
}
