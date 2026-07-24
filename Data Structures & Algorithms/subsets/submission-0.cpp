class Solution {
public:
    vector<vector<int>> ans;
    void combine(vector<int>& nums, vector<int>& currComb, int i){
        if(i == nums.size()){
            ans.push_back(currComb);
            return;
        }
        currComb.push_back(nums[i]);
        combine(nums, currComb, i+1);
        currComb.pop_back();
        combine(nums, currComb, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currComb;
        combine(nums, currComb, 0);
        return ans;
    }
};
