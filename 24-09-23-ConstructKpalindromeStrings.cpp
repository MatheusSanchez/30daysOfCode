/*
    https://leetcode.com/problems/construct-k-palindrome-strings/description/
    Time: O(n+n) -> O(n)   n == s.size()
    Space: O(n)
*/

class Solution {
   public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        unordered_map<char, int> hash;

        for (int i = 0; i < s.size(); i++) {  // O(n) | // O(n) n == s.size()
            hash[s[i]]++;
        }

        int oddValues = 0;

        for (auto u : hash) {  // O(n)
            if (u.second % 2 != 0) {
                oddValues++;
            }
        }

        if (oddValues > k) {
            return false;
        }

        return true;
    }
};