class Solution {
public:
    bool isPalindrome(string s) {
        string c = "";
        for(char i : s){
            if(isalnum(i)){
                c += tolower(i);
            }
        }
        int l = 0, r = c.length()-1;
        while(l <= r){
            if(c[l] != c[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
