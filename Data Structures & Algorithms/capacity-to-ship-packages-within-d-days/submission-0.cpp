class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity){
        int d = 1, weight = 0;
        for(int w : weights){
            weight += w;
            if(weight > capacity){
                weight = w;
                d++;
            }
            if(d > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0], r = 0;
        for(int w : weights){
            l = max(l, w);
            r += w;
        }
        int ans = r;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(weights, days, mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};