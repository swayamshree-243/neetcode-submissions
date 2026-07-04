class Solution {
public:
    void combination(vector<int>& nums, int idx, int remTarget, vector<int>& currComb, vector<vector<int>>& ans){
        if(remTarget == 0){
            ans.push_back(currComb);
            return;
        }
        if(remTarget < 0) return;
        if(idx == nums.size()) return;
        currComb.push_back(nums[idx]);
        combination(nums, idx, remTarget-nums[idx], currComb, ans);
        currComb.pop_back();
        combination(nums, idx+1, remTarget, currComb, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currComb;
        vector<vector<int>> ans;
        combination(nums, 0, target, currComb, ans);
        return ans;
    }
};
