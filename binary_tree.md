# 二叉树遍历

### 目录

---

首先给出树节点定义:

```c++
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
```

---

递归调用

```c++
void pre_order_recursion(TreeNode *node) {
    if (!node) return;
    do_sth(node);
    pre_order_recursion(node->left);
    pre_order_recursion(node->right);
}
```

```c++
void in_order_recursion(TreeNode *node) {
    if (!node) return;
    in_order_recursion(node->left);
    do_sth(node);
    in_order_recursion(node->right);
}
```

```c++
void post_oder_recursion(TreeNode *node) {
    if (!node) return;
    post_order_recursion(node->left);
    post_order_recursion(node->right);
    do_sth(node);
}
```

非递归

```c++
void pre_order_stack1(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        do_sth(node);
        if (node->right) st.push(st->right);
        if (node->left) st.push(st->left);
    }
}
```

```c++
void pre_order_stack2(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (node || !st.empty()) {
        while (node) {
            do_sth(node);
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        node = node->right;
    }
}
```

```c++
void in_order_stack(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (node || !st.empty()) {
        while (node) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        do_sth(node);
        node = node->right;
    }
}
```

```c++
void post_order_stack1(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    st1.push(root);
    while (!st1.empty()) {
        TreeNode *node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    while (!st2.empty()) {
        do_sth(st2.top());
        st2.pop();
    }
}
```

```c++
void post_order_stack2(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *last = root;
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node->left && node->left != last && node->right != last) {
            st.push(node->left);
        } else if (node->right && node->right != last) {
            st.push(node->right);
        } else {
            st.pop();
            last = node;
            do_sth(node);
        }
    }
}
```

```c++
void level_traversal(TreeNode *root) {
    if (!root) return;
    Queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        do_sth(node);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```









