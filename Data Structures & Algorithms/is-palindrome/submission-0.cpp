class Solution {
public:
    bool isPalindrome(string s) {
        string c = "";
        for(char i : s){
            if(isalnum(i)) c += tolower(i);
        }
        int n = c.length();
        int l = 0, r = n-1;
        while(l <= r){
            if(c[l] != c[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
