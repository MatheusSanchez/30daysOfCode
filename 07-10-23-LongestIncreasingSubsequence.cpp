/*
    Time: O(n²) 
    Space: O(n)
    https://leetcode.com/problems/longest-increasing-subsequence/description/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> longest(nums.size(), 1);
        int maxLongest = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = i; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    longest[i] = max(longest[i], 1 + longest[j]);
                    maxLongest = max(longest[i],maxLongest);
                }
            }
        }

        return maxLongest;
    }
};