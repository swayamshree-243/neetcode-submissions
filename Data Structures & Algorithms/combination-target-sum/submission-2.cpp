class Solution {
public:
    void combination(vector<int>& nums, int target, int index, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        } 
        if(target < 0) return;
        if(index == nums.size()) return;
        curr.push_back(nums[index]);
        combination(nums, target-nums[index], index, curr, ans);
        curr.pop_back();
        combination(nums, target, index+1, curr, ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        combination(nums, target, 0, curr, ans);
        return ans;
    }
};
