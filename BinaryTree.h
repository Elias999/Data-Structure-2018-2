//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;
//Στην κλάση πρέπει να εχω μια εγραφη για το υψος καθω και ενα c>1 b>0 επιπλέον θα πρέπει να φτίαξω μια συνάρτηση που θα υπολογίζει το depth και height
class BinarySearchTree{

    private:
        struct tree_node{
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
        int b=0;//Το οποίο γίνετε +1 οταν τελέιωσει η πρώτη διαγραφη και γινέτε ξανα 0 μετα απο ανακατασκευή
        float c;//Θα δωθεί απο τον χρήστη
        int sum_items=0;

    public:
        BinarySearchTree(){
           root = NULL;
        }

        bool isEmpty() const { return root==NULL; }

        void print_inorder();

        void inorder(tree_node*);

        void print_preorder();

        void preorder(tree_node*);

        void print_postorder();

        void postorder(tree_node*);

        void insert(int);

        void remove(int);

        void Search(int x);

        int count(tree_node* p,int cnt);

        int FindHeight(tree_node *root){
          if(root == NULL) return -1;
          return max(FindHeight(root->left),FindHeight(root->right)) +1;
        }
};

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d){
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    list<tree_node*> a;
    int depth = 1;


    // is this a new tree?
    if( isEmpty() ) {
      root = t;
    }
    else{
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr){
            parent = curr;
            a.push_front(curr);//αποθηκεύει το μονοπατι προς το t με πρωτο στοιχειο το τελευταιο στοιχείο απο το t
            //cout<<"perasa apo "<<curr->data<<endl;
            //cout<<"lol height "<<FindHeight(curr)<<endl;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
            depth++;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
    }
    cout<<"depth is "<<depth<<endl;
    for(list<tree_node*>::iterator it=a.begin();it !=a.end();it++){
      static int cnt=1;
      cout<<"to stoixeio "<< *it <<" exei y4os "<<FindHeight(*it)<< " kai exei apo katw tou "<<count(*it,cnt)<<" stoixeia"<<endl;
      }
    sum_items++;
}

//epistrefei tin theisi tou stoaixeio x
void BinarySearchTree::Search(int x){
  tree_node* curr;
  tree_node* parent;
  curr = root;
  bool found = false;


  while(curr != NULL){
    if (x == curr->data){
      found=true;
      break;
    }
    else{
        parent = curr;
        if(x>curr->data) curr = curr->right;
        else curr = curr->left;
    }
  }
  if (found == true) {
    cout<<" to brika stin thesi "<< curr;
  }
  else cout<<"mpouxou"<<endl;
  return;
}

void BinarySearchTree::remove(int d){
    //Locate the element
    bool found = false;
    if(isEmpty()){
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    tree_node* curr;
    tree_node* parent;
    curr = root;

    while(curr != NULL){
         if(curr->data == d){
            found = true;
            break;
         }
         else{
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found){
        cout<<" Data not found! "<<endl;
        return;
    }

		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL)){
       if(curr->left == NULL && curr->right != NULL){
           if(parent->left == curr){
             parent->left = curr->right;
             delete curr;
           }
           else{
             parent->right = curr->right;
             delete curr;
           }
       }
       else{ // left child present, no right child
          if(parent->left == curr){
             parent->left = curr->left;
             delete curr;
           }
           else{
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	       curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

void BinarySearchTree::print_inorder(){
  inorder(root);
}

void BinarySearchTree::inorder(tree_node* p){
    if(p != NULL){
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

int BinarySearchTree::count(tree_node* p,int cnt){
  if(p){
    cnt++;
    if (p->left) {
      count(p->left,cnt);
    }
    if (p->right){
      count(p->right,cnt);
    }
  }
  return cnt;
}

void BinarySearchTree::print_preorder(){
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p){
    if(p != NULL){
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder(){
    postorder(root);
}

void BinarySearchTree::postorder(tree_node* p){
    if(p != NULL){
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else return;
}
