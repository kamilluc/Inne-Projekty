#include <iostream>

using namespace std;

struct BST{
    int val;
    BST * left;
    BST * right;
    BST * parent;
};

void insert_BST(BST*& root, int x, BST* p=NULL){ //wstawianie elementu do drzewa BST
    if (root == NULL){
        root = new BST;
        root->val=x;
        root->left=NULL;
        root->right=NULL;
        if(p) root->parent=p;
    }else if(x < root->val){
        insert_BST(root->left,x,root);
    }else{
        insert_BST(root->right,x,root);
    }
}

BST* Build_tree(int *tab, int size){ //tworzenie drzewa BST z wektora danych
    BST *root=NULL;
    for (int i=0; i<size; i++){
        insert_BST(root,tab[i]);
    }
    return root;
}

void inorder(BST* x ){ //wypisywanie drzewa BST w posortowany sposob
  if(x){
    inorder(x->left);
    cout << x->val << ", ";  // tutaj przetwarzamy bie¿¹cy wêze³
    inorder(x->right);
  }
}

BST * search_BST(BST* root, int x){
    if(root){
        if(root->val == x) return root;
        if(root->val > x) search_BST(root->left,x);
        if(root->val < x) search_BST(root->right,x);
    }else return NULL;
}

BST * min(BST*root){
    while(root->left)
        root = root->left;
    return root;
}

BST* max(BST* root){
    while(root->right){
        root=root->right;
    }
    return root;
}

BST* nastepnik(BST* root){
    BST* p;
      if(root){cout<<"aaA";
        if(root->right) return min(root->right);
        else{
            p=root->parent;
            while(p && (root == p->right)){
                root = p;
                p = p->parent;
            }
            return p;
        }
      }
    return root;
}

int main()
{
    int tab[10] = {5,8,2,3,10,11,9,7,12,10};
    BST * root=Build_tree(tab,10);
    cout << "aaa"<<endl;
    inorder(root);
    cout<<endl;
    cout<<nastepnik(search_BST(root,3))->val<<endl;

    return 0;
}
