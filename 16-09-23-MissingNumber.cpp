/*
https://leetcode.com/problems/missing-number/description/
Time O(n), n == tree.size();
Space O(h), h == height(tree);
*/

int missingNumber(vector<int>& nums) {
    int totalSum = ((0 + nums.size()) * (nums.size() + 1)) / 2;

    for (int i = 0; i < nums.size(); i++) {
        totalSum -= nums[i];
    }

    return totalSum;
}

/*
Approach 01 - Try all numbers
search by 0,1,2, ... ,n-1,n;
each search -> O(n) - we need to search n times so O(n²);
Complexity: O(n²)

Approach 02 - Sort and Search
nums.sort(); --> O(nlogn)
As now we got a ordered vector we can perform binary search
binarySearch(vector) -> O(log n)
Complexity: O(nlogn) + O(log n) -> O(nlogn)
*/