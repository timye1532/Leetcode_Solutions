class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // even store the number of even sums including current arr[i]
        // [2, 4, 6], arr[i] = 8, then subarrays are [8], [6, 8], [4, 6, 8], [2, 4, 6, 8]
        // odd store the number of odd sums including current arr[i]
        int res = 0, even = 0, odd = 0;
        int mod = int(1e9+7);

        for (int num : arr) {
            if (num % 2 == 0) {
                even++;
            } else {
                int tmp = odd;
                odd = even;
                even = tmp;
                odd++;
            }
            res = (res % mod + odd % mod) % mod;
        }
        return res;
    }
};