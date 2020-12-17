#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 21:58:57
 * @LastEditTime: 2020-12-16 22:52:09
 * @Description: file content
https://leetcode-cn.com/problems/delete-operation-for-two-strings/
583. 两个字符串的删除操作   middle
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。

解答：同lc1143最长公共子序列类似，dp[i][i]代表s1[..i]和s2[..j]的最长距离；
    详情见lc1143
复杂度：
    时间O(N^2)
    空间O(N^2)
 */


    int minDistance(string word1, string word2) {
        int m = word1.size(), n= word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // 初始化
        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=n; i++){
            dp[0][i] = i;
        }
        // dp
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1])    dp[i][j] = dp[i-1][j-1];
                else    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;   
            }
        }
        return dp[m][n];
    }