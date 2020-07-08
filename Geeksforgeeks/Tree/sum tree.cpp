
problem statement: https://practice.geeksforgeeks.org/problems/sum-tree/1

int helper(Node* node, bool& res){
    if(!node)
        return 0;
        
    if(!node->left && !node->right)
        return node->data;
        
    int left = helper(node->left, res);
    int right = helper(node->right, res);
    
    if(left + right != node->data)
        res = false;
    
    return (node->data + left + right);
}

bool isSumTree(Node* root){
    bool res = true;
    helper(root, res);
    return res;
}
