

    void insert(int x, tree_node* leaf)
    {
        if(leaf == NULL)
        {
            leaf = new node;
            leaf->data = x;
            leaf->left = t->right = NULL;
        }
        else if(x < leaf->data)
        {
            t->left = insert(x, t->left);
            if(FindHeight(leaf->left) - FindHeight(leaf->right) == 2)
            {
                if(x < leaf->left->data)
                    leaf = SRR(leaf);
                else
                    leaf = DRR(leaf);
            }
        }
        else if(x > leaf->data)
        {
            leaf->right = insert(x, leaf->right);
            if(FindHeight(t->right) - FindHeight(t->left) == 2)
            {
                if(x > leaf->right->data)
                    leaf = SLR(leaf);
                else
                    leaf = DLR(leaf);
            }
        }
    }

    tree_node* SRR(tree_node* &leaf)
    {
        tree_node* swp = leaf->left;
        leaf->left = swp->right;
        swp->right = leaf;
        return swp;
    }

    tree_node* SLR(tree_node* &leaf)
    {
        tree_node* swp = leaf->right;
        leaf->right = swp->left;
        swp->left = leaf;
        return swp;
    }

    tree_node* DLR(tree_node* &leaf)
    {
        leaf->right = SRR(leaf->right);
        return SLR(leaf);
    }

    tree_node* DRR(tree_node* &leaf)
    {
        leaf->left = SLR(leaf->left);
        return SRR(leaf);
    }
