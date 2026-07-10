class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currFreq = 0, maxFreq = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 1){
                currFreq++;
                maxFreq = max(maxFreq, currFreq);
            } 
            else{
                currFreq = 0;
                l = r+1;
            }
        }
        return maxFreq;
    }
};