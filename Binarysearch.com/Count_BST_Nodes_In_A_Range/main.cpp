/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, int lo, int hi) {
    if(root == nullptr)
        return 0;
    int ans = 0;
    stack<Tree*> s;
    s.push(root);
    while(!s.empty()){
        Tree* u = s.top();
        s.pop();
        if(lo <= u->val && u->val <= hi)
            ans++;
        if(u->left != nullptr)
            s.push(u->left);
        if(u->right != nullptr)
            s.push(u->right);
    }
    
    return ans;
}