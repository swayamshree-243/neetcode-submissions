class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int m = 0;
        int current, streak;
        int n = s.size();

        for(int i : s){
            if(s.find(i-1) == s.end()){
                current = i;
                streak = 1;
                while(s.find(current + 1) != s.end()){
                    current++;
                    streak++;
                }
                m = max(streak, m);
            }
        }
        return m;
    }
};
