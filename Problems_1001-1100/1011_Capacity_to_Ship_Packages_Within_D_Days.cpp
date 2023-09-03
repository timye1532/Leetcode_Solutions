class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = -1, r = 0;
        for (int weight : weights) {
            l = max(l, weight);
            r = r + weight;
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check_valid(weights, days, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check_valid(weights, days, l)) return l;
        return r;
    }

    bool check_valid(vector<int>& weights, int days, int capacity) {
        int day_sum = 1, cur_weight = 0;
        int i = 0;
        while (i < weights.size()) {
            int weight = weights[i];
            if (weight > capacity) return false;
            cur_weight += weight;
            if (cur_weight > capacity) {
                cur_weight = weight;
                day_sum++;
            }
            i++;
        }
        return (day_sum <= days);
    }
};