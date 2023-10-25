/*
Time: O(n*m)         n = text1.size() m = text2.size()
Space: O(n*m)
https://leetcode.com/problems/longest-common-subsequence/description/
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));

        for(int i = text1.size()-1; i >= 0; i--){ 
            
            for(int j = text2.size()-1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }

        }

        return dp[0][0];
    }
};