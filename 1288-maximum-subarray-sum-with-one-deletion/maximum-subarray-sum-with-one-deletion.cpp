class Solution {
public:
    int maximumSum(vector<int>& arr) {
        constexpr int kMin = INT_MIN / 2;
        int ans = kMin;
        int zero = kMin;
        int one = kMin;

        for (const int a : arr) {
            one = max({a, one + a, zero});
            zero = max(a, zero + a);
            ans = max(ans, one);
        }

        return ans;
    }
};