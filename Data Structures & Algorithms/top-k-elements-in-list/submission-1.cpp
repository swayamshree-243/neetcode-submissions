class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n] ++;
        }
        vector<vector<int>> f(nums.size() + 1);
        for(auto i : mp){
            f[i.second].push_back(i.first);
        }
        vector<int> ans;
        for(int i = f.size()-1; i >= 0; i--){
            for(int n : f[i]){
                ans.push_back(n);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};
