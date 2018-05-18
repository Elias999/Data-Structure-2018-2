struct node{
  int key;
  node *left;
  node *right;
};

class BinaryTree{
  public:
    BinaryTree();
    ~BinaryTree();

    void insert(int key);
    node *search(int key);
    void erase_tree();

  private:
    void erase_tree(node *leaf);
    void insert(int key,node *leaf);
    node *search(int key, node *leaf);

    node *root;
};

BinaryTree::BinaryTree(){
  root=NULL;
}

BinaryTree::~BinaryTree(){
  erase_tree();
}

BinaryTree::erase_tree(node *leaf){
  if(leaf!=NULL){
    erase_tree(leaf->left);
    erase_tree(leaf->right);
    delete leaf;
  }
}
void BinaryTree::insert(int key, node *leaf)
{
  if(key< leaf->key)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }
  else if(key>=leaf->key)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *BinaryTree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key)
      return leaf;
    if(key<leaf->key)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void BinaryTree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key=key;
    root->left=NULL;
    root->right=NULL;
  }
}

node *BinaryTree::search(int key)
{
  return search(key, root);
}

void BinaryTree::destroy_tree()
{
  destroy_tree(root);
}
