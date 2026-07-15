class Solution {
public:
    bool check(vector<int>& nums, int k, int maxSum){
        int sum = 0, n = 1;
        for(int i : nums){
            sum += i;
            if(sum > maxSum){
                sum = i;
                n++;
            }
            if(n > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = nums[0], r = 0;
        for(int n : nums){
            l = max(l, n);
            r += n;
        }
        int ans = r;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(nums, k, mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};