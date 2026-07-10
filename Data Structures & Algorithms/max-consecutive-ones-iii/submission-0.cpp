class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int f = 0, longest = 0, l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 1) f++;
            while((r-l+1) - f > k){
                if(nums[l] == 1) f--;
                l++;
            }
            longest = max(longest, (r-l+1));
        }
        return longest;
    }
};