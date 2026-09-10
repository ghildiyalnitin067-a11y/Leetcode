class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return pair<int,int>{0, 0};

            auto L = dfs(node->left);
            auto R = dfs(node->right);

            int sum = node->val + L.first + R.first;
            int cnt = 1 + L.second + R.second;

            ans += (node->val == sum / cnt);

            return pair<int,int>{sum, cnt};
        };

        dfs(root);
        return ans;
    }
};