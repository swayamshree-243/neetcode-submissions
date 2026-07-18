class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        long long time = 0;
        for(int n : piles){
            time += (n + k- 1)/ k;
            if(time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = piles[0], l = 1;
        for(int i = 1; i < piles.size(); i++){
            r = max(r, piles[i]);
        }
        int k = r;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(piles, h, mid)){
                k = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return k;
    }

};
