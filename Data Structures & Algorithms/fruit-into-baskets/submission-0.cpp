class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, maxNum = 0;
        unordered_map<int, int> mp;
        for(int r = 0; r < fruits.size(); r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                if(mp[fruits[l]] == 1) mp.erase(fruits[l]);
                else mp[fruits[l]]--;
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }  
        return maxNum;
    }
};