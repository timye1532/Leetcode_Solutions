class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int x = 0, y = 1, z = 1;
        for (int i = 0; i < n - 2; i++)
        {
            int tmp = x + y + z;
            x = y;
            y = z;
            z = tmp;
        }
        return z;
    }
};