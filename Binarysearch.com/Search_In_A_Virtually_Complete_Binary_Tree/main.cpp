/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root, int target) {
    if(root == nullptr)
        return 0;
    stack<Tree*> s;
    bool flag = 0;
    s.push(root);
    while(!s.empty()){
        Tree* u = s.top();
        s.pop();
        if(u->val == target)
            flag = 1;
        if(u->left != nullptr)
            s.push(u->left);
        if(u->right != nullptr)
            s.push(u->right);
    }
    return flag;

}