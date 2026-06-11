class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i];
            for(int j = i + 1; j < n; j++){
                if(x == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};