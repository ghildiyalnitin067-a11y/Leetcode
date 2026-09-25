class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        
        for (int i = 0; i < ops.size(); i++) {
            string op = ops[i];
            
            if (op == "C") {
                record.pop_back();
            }
            else if (op == "D") {
                int last = record[record.size() - 1];
                record.push_back(last * 2);
            }
            else if (op == "+") {
                int last = record[record.size() - 1];
                int secondLast = record[record.size() - 2];
                record.push_back(last + secondLast);
            }
            else {
                int num = stoi(op);
                record.push_back(num);
            }
        }
        
        int total = 0;
        for (int i = 0; i < record.size(); i++) {
            total = total + record[i];
        }
        
        return total;
    }
};