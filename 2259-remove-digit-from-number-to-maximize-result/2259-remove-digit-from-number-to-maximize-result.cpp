class Solution {
public:
    string removeDigit(string number, char digit) {
        int last;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                last=i;
                if(i<number.size()-1 && number[i+1]>digit){
                    number.erase(number.begin()+i);
                    return number;
                }
            }
        }
        number.erase(number.begin()+last);
        return number;
    }
};