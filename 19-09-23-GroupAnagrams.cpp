/*
https://leetcode.com/problems/group-anagrams/description
Time: O((n * mlogm) + n) -> O(n * mlogm) n == strs.size() m == lenght of the
bigger string; Space: O(n)
*/
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupAnagram;

        for (int i = 0; i < strs.size(); i++) {
            string actualString = strs[i];
            sort(actualString.begin(), actualString.end());
            groupAnagram[actualString].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto u : groupAnagram) {
            ans.push_back(u.second);
        }

        return ans;
    }
};