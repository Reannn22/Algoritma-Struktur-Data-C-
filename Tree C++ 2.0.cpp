#include <iostream>
using namespace std;

typedef struct Node *nAddress;
typedef int infotype;
struct Node{
    infotype info;
    nAddress left, right, parent;
};

nAddress root;

nAddress alloc(infotype X){
    nAddress newNode;
    newNode = new Node();
    newNode->info = X;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void create(infotype info){ 
    if (root != NULL){
        cout << endl << "Tidak bisa membuat root" << endl; 
    }
    else{
        root = alloc(info);
        cout << endl << "Root ditambah" << endl;
    }
}

nAddress insertLeft(infotype info, nAddress nodeParent){
    if (nodeParent->left != NULL){
        cout << endl << "Gagal menambah insert left" << endl;
        return NULL;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->left = newNode; 
        newNode->parent = nodeParent; 
        cout << info << " ditambahkan sebagai anak kiri dari " << nodeParent->info << endl;
        return newNode;
    }
}

nAddress insertRight(infotype info, nAddress nodeParent){
    if (nodeParent->right != NULL){
        cout << endl << "Gagal menambah insert right" << endl;
        return NULL;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->right = newNode;
        newNode->parent = nodeParent;
        cout << info << " ditambahkan sebagai anak kanan dari " << nodeParent->info << endl;
        return newNode;
    }
}

void preOrder(nAddress P){
    if (P != NULL){
        cout << P->info << " ";
        preOrder(P->left);
        preOrder(P->right);
    }
}

void inOrder(nAddress P){
    if (P != NULL){
        inOrder(P->left);
        cout << P->info << " ";
        inOrder(P->right);
    }
}

void postOrder(nAddress P){
    if (P != NULL){
        postOrder(P->left);
        postOrder(P->right);
        cout << P->info << " ";
    }
}

int main(){
    nAddress node_0, node_1, node_2, node_3, node_4, node_5, node_6, node_7, node_8 ,node_9;

    create(1);
    node_2 = insertLeft(2, root);
    node_3 = insertRight(3, root);
    node_4 = insertLeft(4, node_2);
    node_5 = insertRight(5, node_2);
    node_6 = insertRight(6, node_3);
    node_7 = insertRight(7, node_5);
    node_8 = insertLeft(8, node_6);
    node_9 = insertRight(9, node_6);

    cout << endl << "Traversal Tree:" << endl;

    cout << "Pre-Order: ";
    preOrder(root);
    cout << endl;

    cout << "In-Order: ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}
