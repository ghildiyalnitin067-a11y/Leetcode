class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        for (auto& seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int result = (n - reserved.size()) * 2;

        for (auto& [row, seats] : reserved) {
            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat)) {
                    left = false;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat)) {
                    middle = false;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat)) {
                    right = false;
                }
            }

            if (left && right) {
                result += 2;
            } 
            else if (left || middle || right) {
                result += 1;
            }
        }

        return result;
    }
};