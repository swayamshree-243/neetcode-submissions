class Solution {
public:
    int findMin(vector<int> &nums) {
        int st = 0, end = nums.size() - 1;
        int min = INT_MAX;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[st] < nums[end]){
                if(nums[st] < min){
                    min = nums[st];
                }
                break;
            }
            if(nums[st] <= nums[mid]){
                if(nums[st] < min){
                    min = nums[st];
                }
                
                st = mid + 1;
            }
            else{
                if(nums[mid] < min){
                    min = nums[mid];
                }
                
                end = mid - 1;
            }
        }
        return min;
    }
};
