class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length()+1, false);
        dp[0] = true;
        for(int i = 0; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.count(s.substr(j, i-j)) != 0){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
