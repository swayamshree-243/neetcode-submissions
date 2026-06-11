class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(char c : s){
            if(isalnum(c)){
                a += tolower(c);
            }
        }
        int l = 0, r = a.length()-1;
        while(l <= r){
            if(a[l] != a[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
