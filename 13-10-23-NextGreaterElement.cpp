/*

Time: O(n) == n nums1,size() + nums2.size()
Space: O(m) == nums2.size()
    
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        unordered_map<int, int> nextGreaterElement;
         
        for(int i = 0; i < nums2.size(); i++){ 

            while(!s.empty() && s.top() < nums2[i]){
                nextGreaterElement[s.top()] =  nums2[i];
                s.pop();
            }  

            s.push(nums2[i]); 
        }

        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            if(nextGreaterElement.find(nums1[i]) != nextGreaterElement.end()){
                ans.push_back(nextGreaterElement[nums1[i]]);
            }else{
                ans.push_back(-1);
            }
        }


        return ans;

    }
};



