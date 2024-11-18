#include <iostream>
using namespace std;

typedef struct Node *nAddress;
typedef int infotype;
struct Node{
    infotype info;
    nAddress left, right, parent;
};

nAddress root;

nAddress alloc(infotype x){
    nAddress newNode;
    newNode = new Node();
    newNode -> info = x;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    return newNode;
}

void create(infotype info){ 
    if (root!=NULL){
        cout << endl << "Can't make root!!!" << endl; 
    }
    else{
        root = alloc(info);
        cout << endl << "Root added" << endl;
    }
}

nAddress insertLeft (infotype info, nAddress nodeParent){

    if (nodeParent->left != NULL){
        cout << endl << "Failed to insert left!!!" << endl;
        return NULL;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->left = newNode ; 
        newNode->parent = nodeParent; 
        cout << info << " added as left child of " << nodeParent->info << endl;
        return newNode;
    }
}

nAddress insertRight (infotype info, nAddress nodeParent){
    if(nodeParent->right != NULL){
        cout << endl << "Failed to insert right!!!" << endl;
        return NULL;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->right = newNode;
        newNode->parent = nodeParent;
        cout << info << " added as right child of " << nodeParent->info << endl;
        return newNode;
    }
}

void print(nAddress P = root){
    if (!root){
        cout << "No tree inside!!!" << endl;
    }
    else {
        if (P!=NULL){
            cout << P->info << " ";
            print(P->left); 
            print(P->right); 
        }
    }
}

void clear(nAddress P){
    if (P == NULL){
        return;
    }
    else {
        clear(P->left);   
        clear(P->right); 

        cout << endl << "Deleting node : " << P->info;
        delete P;
    }
}

void deleteTree(){
    clear(root);
    cout << endl << "Tree deleted" << endl;
}

int main(){
    nAddress node_0, node_1, node_2, node_3, node_4, node_5, node_6, node_7, node_8 ,node_9;
    create(1);
    node_2 = insertLeft(2, root);
    node_3 = insertRight(1, root);
    node_4 = insertLeft(1, node_2);
    node_5 = insertRight(4, node_2);
    node_6 = insertRight(0, node_3);
    node_7 = insertRight(0, node_5);
    node_8 = insertLeft(9, node_6);
    node_9 = insertRight(8, node_6);
    cout << endl << "Isi tree : " << endl;
    print();
}
