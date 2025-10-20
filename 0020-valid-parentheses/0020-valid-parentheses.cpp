class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n=s.size();
        map<char, int> mpp = {{'(', 3}, {'{', 1}, {'[', 2}, {')', -3}, {'}', -1}, {']', -2}};
        for(int i=0;i<n;i++){
            int val = mpp[s[i]];
            if(val<0){
                if(st.empty()||(st.top()+mpp[s[i]]!=0))return false;
                else{
                    st.pop();
                }
            }
            else{
                st.push(mpp[s[i]]);
            }
        }
        return st.empty();
    }
};