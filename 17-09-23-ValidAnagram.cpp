/*
https://leetcode.com/problems/valid-anagram/
Time O(n), n == s.size();
Space O(n), n == s.size();
*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> hashAnagram;

        for (int i = 0; i < s.size(); i++) {  // O(n)
            hashAnagram[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {  // O(n)
            hashAnagram[t[i]]--;

            if (hashAnagram[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};

/*
Approach 01 - Count all letters O(n²) | O(1)

Count how many 'a' string s has -> O(n)
Check if string t has the same amount of 'a' as string s -> O(n)
Count how many 'b' string s has -> O(n)
Check if string t has the same amount of 'b' as string s -> O(n)
...
Count how many 'z' string s has -> O(n)
Check if string t has the same amount of 'z' as string s -> O(n)
Considering only 26 possible characteres -> 26 * n * n -> O(n²)


Approach 02 - Sort

s.sort(); --> O(nlogn)
t.sort(); --> O(nlogn)
aaabbbccc aaabbbccc -> compair if s[i] == t[i] -> O(n)
Complexity: O(nlogn) + O(nlogn) + O(n) -> O(nlogn)
*/