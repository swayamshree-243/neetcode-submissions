class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, maxNum = 0, freq = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 1) freq++;
            while((r-l+1) - freq > k){
                if(nums[l] == 1) freq--;
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }
        return maxNum;
    }
};