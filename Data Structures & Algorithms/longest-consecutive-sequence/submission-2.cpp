class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        sort(nums.begin(), nums.end());
        int k = 1, m = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] == nums[i]) continue;
            else if(nums[i+1] == nums[i] + 1){
                k++;
                m = max(k, m);
            }
            else{
                k = 1;
            }
        }
        return m;
    }
};
