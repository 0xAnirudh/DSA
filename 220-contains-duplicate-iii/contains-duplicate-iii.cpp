class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            long long v = nums[i];
            auto it = s.lower_bound(v - valueDiff);
            if (it != s.end() && *it <= v + valueDiff) return true;
            s.insert(v);
            if (i >= indexDiff) s.erase((long long)nums[i - indexDiff]);
        }
        return false;
    }
};
