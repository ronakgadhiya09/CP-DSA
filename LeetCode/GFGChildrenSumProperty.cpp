class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(!root || (root->left==nullptr && root->right==nullptr)) return 1;
     
     int left = isSumProperty(root->left);
     int right = isSumProperty(root->right);
     
     if(left==0 || right==0) return 0;
     
     int val = 0;
     if(root->left) val += root->left->data;
     if(root->right) val += root->right->data;
     
     return root->data == val;
    }
};
