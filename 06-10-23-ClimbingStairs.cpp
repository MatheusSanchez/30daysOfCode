/*
    Time: O(n) 
    Space: O(n)
    https://leetcode.com/problems/climbing-stairs/description/
*/
class Solution {
public:
    int climbStairs(int n) {
      vector<int>howMany(46, -1); // O(n) O(n)

      howMany[0] = 1;
      howMany[1] = 1;
      howMany[2] = 2;
      howMany[3] = 3;

      return climb(n, howMany);

    }

    // howMany[1,1,2,3,-1,-1]
    // climb(6) howMany[6] = climb(5) + climb(4)*
    // climb(5) howMany[5] = climb(4) + climb(3)*
    // climb(4) howMany[4] = 3 + 2
    // climb(3) return 3
    // climb(2) return 2

    int climb(int n, vector<int> &howMany){ // O(n) O(n)

        if(howMany[n] != -1){
            return howMany[n];
        }

        howMany[n] = climb(n-1, howMany) + climb(n-2, howMany);

        return howMany[n];
    }

};