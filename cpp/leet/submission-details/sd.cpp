/**
 ** Definition for binary tree
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
    public:
        typedef pair<int, TreeNode *> TPair;
        typedef vector<vector<int> > TVector;
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            TVector v;
            if (root == NULL) return v;

            queue<TPair> q;
            q.push(TPair(0, root));
            v.push_back(vector<int>());
            while (!q.empty()) {
                TPair tp = q.front();
                q.pop();

                TreeNode *node = tp.second;
                int level = tp.first;
                if (level == v.size()) {
                    v.push_back(vector<int>());
                }
                v[level].push_back(node->val);

                if (node->left) q.push(TPair(level + 1, node->left));
                if (node->right) q.push(TPair(level + 1, node->right));
            }

            for (int i = 1; i < v.size(); i += 2) {
                reverse(v[i].begin(), v[i].end());
            }
            return v;
        }
};
