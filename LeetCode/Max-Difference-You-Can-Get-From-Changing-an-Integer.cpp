class Solution {
public:
    int maxDiff(int num) {
        vector<int> number;
        int temp = num;
        while (temp) {
            number.push_back(temp % 10);
            temp /= 10;
        }

        int max_num = num;
        int min_num = num;

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (x == y) continue;

                int cur_num = 0;
                int mult = 1;
                bool valid = true;

                for (int i = 0; i < number.size(); i++) {
                    int digit = number[i];
                    if (digit == x) digit = y;

                    if (i == number.size() - 1 && digit == 0) {
                        valid = false;
                        break;
                    }

                    cur_num += digit * mult;
                    mult *= 10;
                }

                if (valid && cur_num != 0) {
                    max_num = max(max_num, cur_num);
                    min_num = min(min_num, cur_num);
                }
            }
        }

        return max_num - min_num;
    }
};
