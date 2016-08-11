/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**这是一道很经典的题目，考的非递归的中序遍历。其实这道题等价于写一个二叉树中序遍历的迭代器。
  * 需要内置一个栈，一开始先存储到最左叶子节点的路径。
  * 在遍历的过程中，只要当前节点存在右孩子，则进入右孩子，存除从此处开始到当前子树里最左叶子节点的路径。
  **/
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        allLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = myStack.top();
        myStack.pop();
        allLeft(tmp -> right);//cause we need to find the next smallest num(which is the second small one), the left most child's, right child's, left most child
        return tmp -> val;
    }

private:
    void allLeft(TreeNode *node) {
        for(; node; myStack.push(node), node = node -> left);// do not forget ";"
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */