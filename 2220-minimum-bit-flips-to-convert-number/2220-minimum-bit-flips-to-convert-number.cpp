class Solution {
public:
    int minBitFlips(int start, int goal) { 
        int num = (start) ^( goal);
        return __builtin_popcount(num); 
    }
};