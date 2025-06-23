#include<bits/stdc++.h>
using namespace std;

class Tree{
public:
    int val;
    Tree* left = NULL;
    Tree* right = NULL;
    Tree* parent = NULL;
    int h;

    Tree(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }

    void insert(int val){
        if(this->val >= val && this->left == NULL){
            this->left = new Tree(val);
            this->left->parent = this;
        }
        else if(this->val >= val && this->left != NULL){
            this->left->insert(val);
        }
        else if(this->val < val && this->right == NULL){
            this->right = new Tree(val);
            this->right->parent = this;
        }
        else{
            this->right->insert(val);
        }
    }

    int height(){
        int lh = -1;
        if(this->left != NULL){
            lh = this->left->height();
        }

        int rh = -1;
        if(this->right != NULL){
            rh = this->right->height();
        }

        this->h = max(lh, rh)+1;
        return this->h;
    }

    void in_order(bool h_chk = 1){
        if(h_chk == 1)this->height();

        if(this->left != NULL){
            this->left->in_order(0);
        }

        cout<<this->val<<"("<<this->h<<") ";

        if(this->right != NULL){
            this->right->in_order(0);
        }

    }

    void left_rotate(int val, Tree* root){
        if(this->left != NULL && val < this->val){
            this->left->left_rotate(val, root);
        }
        else if(this->right != NULL && val > this->val){
            this->right->left_rotate(val, root);
        }
        else{
            Tree* y = this->right;
            this->right = y->left;
            if(y->left != NULL){
                y->left->parent = this;
            }
            y->parent = this->parent;
            if(this->parent == NULL){
                root = y;
            }
            else if(this == this->parent->left){
                this->parent->left = y;
            }
            else{
                this->parent->right = y;
            }
            y->left = this;
            this->parent = y;
        }
    }

};



int main(){

    Tree* root = new Tree(10);
    root->insert(20);
    root->insert(15);
    root->insert(7);
    root->insert(8);
    root->insert(1);
    root->insert(90);
    root->insert(23);

    root->in_order();
    root->left_rotate(7, root);
    root->in_order();

    return 0;
}
