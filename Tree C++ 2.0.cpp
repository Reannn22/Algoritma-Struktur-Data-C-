#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *nAddress;
struct Node{
    infotype info;
    nAddress left, right, parent;
};

nAddress root;

nAddress alloc(infotype X){
    nAddress newNode;
    newNode = new Node();
    newNode->info = X;
    newNode->left = 0;
    newNode->right = 0;
    newNode->parent = 0;
    return newNode;
}

void create(infotype info){ 
    if (root != 0){
        cout<<"Tidak bisa membuat root"<<endl; 
    }
    else{
        root = alloc(info);
        cout<<"Root ditambah"<<endl;
    }
}

nAddress insertLeft(infotype info, nAddress nodeParent){
    if (nodeParent->left != 0){
        cout<<"Gagal menambah insert left"<<endl;
        return 0;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->left = newNode; 
        newNode->parent = nodeParent; 
        cout<<info<<" ditambahkan sebagai anak kiri dari "<<nodeParent->info<< endl;
        return newNode;
    }
}

nAddress insertRight(infotype info, nAddress nodeParent){
    if (nodeParent->right != 0){
        cout<<"Gagal menambah insert right"<< endl;
        return 0;
    }
    else{
        nAddress newNode;
        newNode = alloc(info);
        nodeParent->right = newNode;
        newNode->parent = nodeParent;
        cout<<info<<" ditambahkan sebagai anak kanan dari "<<nodeParent->info<<endl;
        return newNode;
    }
}

void PreOrder(nAddress P){
    if(P != 0){
        cout<<P -> info<<" ";
        PreOrder(P -> left);
        PreOrder(P -> right);
    }
}

void InOrder(nAddress P){
    if(P != 0){
        InOrder(P -> left);
        cout<<P -> info<<" ";
        InOrder(P -> right);
    }
}

void PostOrder(nAddress P){
    if(P != 0){
        PostOrder(P -> left);
        PostOrder(P -> right);
        cout<<P -> info<<" ";
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
    PreOrder(root);
    cout << endl;

    cout << "In-Order: ";
    InOrder(root);
    cout << endl;

    cout << "Post-Order: ";
    PostOrder(root);
    cout << endl;

    return 0;
}
