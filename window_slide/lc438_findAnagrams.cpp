#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

/* 
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
438. 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

解法：
    类似lc76， 在哪个基础上更简单（ 看findAnagrams2）；
    findAnagrams()解法相对独立，也更复杂，debug更麻烦；
   

边际条件：
    p="a", 长度为1;



    
 */


    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lo = 0, hi = p.size() - 1, match = 0;
        unordered_map<char, int> needs, window;
        for(char c: p)  needs[c]++;
        for(int i=0; i<=hi; i++){
            if(needs.count(s[i])){
                window[s[i]]++;
                // 避免了s = "aaabaaa", p = "aaa"; a已经少了，但match还再减少变为负数；
                if(window[s[i]] == needs[s[i]])   match++;
            }
        }
        if(match==needs.size()) res.push_back(lo);

        while(hi < s.size()){
            // move left
            char c1 = s[lo];
            if(needs.count(c1)){

                window[c1]--;
                if(window[c1]+1 == needs[c1])  match--;
            }
            lo++;
            // move right
            char c2 = s[hi+1];
            if(needs.count(c2)){
                window[c2]++;
                if(window[c2] == needs[c2])  match++;
            }
            hi++;
            if(match == needs.size())   res.push_back(lo);
        }
        return res;
    }


    vector<int> findAnagrams2(string s, string p) {
    /*  用lc76的框架来做
     */
        vector<int> res;
        int lo = 0, hi = 0;
        unordered_map<char, int> needs, window;
        for (char c : p) needs[c]++;

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
                if(hi - lo == p.size()) res.push_back(lo);
                // move lo
                char c2 = s[lo];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2] < needs[c2])  match--;
                }
                lo++;
            }
        }
        return res;

    }




int main(int argc, char const *argv[])
{
    string s = "aaabaaa", p = "aaa";
    vector<int> res = findAnagrams2(s, p);
    for(int val: res)   cout<<val<<"   ";
    // cout<< findAnagrams(s, p);
    return 0;
}








