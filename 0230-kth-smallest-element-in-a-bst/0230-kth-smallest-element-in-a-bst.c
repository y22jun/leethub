int kthSmallest(struct TreeNode* root,int k)
{
    int cnt=0;
    int res=-1;
    struct TreeNode* curr=root;
    struct TreeNode* pre;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cnt++;
            if(cnt==k)
            {
                res=curr->val;
                break;
            }
            curr=curr->right;
        }
        else
        {
            pre=curr->left;
            while (pre->right!=NULL&&pre->right!=curr) pre=pre->right;
            if (pre->right==NULL) 
            {
                pre->right=curr;
                curr=curr->left;
            } 
            else 
            {
                pre->right = NULL;
                cnt++;
                if(cnt==k) 
                {
                    res=curr->val;
                    break;
                }
                curr=curr->right;
            }
        }
    }
    return res;
}