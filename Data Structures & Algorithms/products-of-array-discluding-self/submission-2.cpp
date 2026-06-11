class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = 1, r = 1;
        vector<int> p(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            p[i] *= l;
            l *= nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            p[i] *= r;
            r *= nums[i];
        }
        return p;
    }
};
