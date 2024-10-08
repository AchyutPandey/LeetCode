class Solution {
    set<pair<int, int>> st1; // Store sum and number of elements for first half
    unordered_map<int, vector<int>> mp; // Store sums for subsets of the second half

    // Generate subsets for the first half
    void gen1(vector<int>& nums, int start, int end, int num, int sum, int i) {
        st1.insert({ sum, num });
        if (i >= end) return;
        gen1(nums, start, end, num + 1, sum + nums[i], i + 1);
        gen1(nums, start, end, num, sum, i + 1);
    }

    // Generate subsets for the second half
    void gen2(vector<int>& nums, int start, int end, int num, int sum, int i) {
        mp[num].push_back(sum);
        if (i >= end) return;
        gen2(nums, start, end, num + 1, sum + nums[i], i + 1);
        gen2(nums, start, end, num, sum, i + 1);
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0); // Calculate total sum
        gen1(nums, 0, n / 2, 0, 0, 0);
        gen2(nums, n / 2, n, 0, 0, n / 2);
        int ans = INT_MAX;

        // Sort sums for each subset of the second half
        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
        }

        // Iterate through sums from the first half
        for (auto it : st1) {
            int sum1 = it.first;
            int num1 = it.second;
            int reqnum = n / 2 - num1; // Needed count from the second half

            // Check if there are sums for the required number in the second half
            if (mp.find(reqnum) == mp.end()) continue;

            // Calculate the required value to minimize the difference
            int reqvalue = totalsum / 2 - sum1;

            // Find the closest sum in the second half using binary search
            auto& vec = mp[reqnum];
            auto itr = lower_bound(vec.begin(), vec.end(), reqvalue);

            // Check the found element
            if (itr != vec.end()) {
                ans = min(ans, abs(2 * (sum1 + *itr) - totalsum));
            }
            // Check the previous element
            if (itr != vec.begin()) {
                --itr;
                ans = min(ans, abs(2 * (sum1 + *itr) - totalsum));
            }
        }
        return ans;
    }
};
