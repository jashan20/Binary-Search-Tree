void inorder(Node* root,vector<int> &v)
    {
        if(root == NULL)
        return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a,b,c;
       inorder(root1,a);
       inorder(root2,b);
       int i=0,j=0;
       // int n= a.size() + b.size();
       while(i< a.size() && j<b.size())
       {
           if(a[i] == b[j])
           {
               c.push_back(a[i]);
               c.push_back(b[j]);
               i++;
               j++;
           }
           else if(a[i] < b[j])
           {
               c.push_back(a[i]);
               i++;
           }
           else
           {
               c.push_back(b[j]);
               j++;
           }
       }
       while(i<a.size())
       {c.push_back(a[i]);i++;}
       while(j<b.size())
       {c.push_back(b[j]);j++;}
       return c;
    }
