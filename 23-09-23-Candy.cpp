/*
    Time: O(n)
    Space: O(1)
    https://leetcode.com/problems/candy/
*/

class Solution {
   public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) {
            return ratings.size();
        }

        vector<int> candyStore(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {  // O(n)
            if (ratings[i] > ratings[i - 1]) {
                candyStore[i] = candyStore[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 1; i > 0; i--) {  // O(n)
            if (ratings[i - 1] > ratings[i]) {
                candyStore[i - 1] = max(candyStore[i] + 1, candyStore[i - 1]);
                ;
            }
        }

        int ans = 0;
        for (int i = 0; i < candyStore.size(); i++) {  // O(n)
            cout << candyStore[i] << endl;
            ans += candyStore[i];
        }

        return ans;
    }
};