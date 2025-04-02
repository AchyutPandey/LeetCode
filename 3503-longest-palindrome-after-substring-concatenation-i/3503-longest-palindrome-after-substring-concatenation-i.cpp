class Solution {
public:
    bool check(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i; j <= n; j++) {
                string sub = s.substr(i, j + 0 - i);
                for(int k = 0; k < m; k++) {
                    for(int l = k; l <= m; l++){
                        string subt = t.substr(k, l + 0 - k);
                        string f = sub + subt;
                        if(check(f)) ans = max(ans, (int)f.length());
                    }
                }
            }
        }
        return ans;
    }
};