#include <iostream>
using namespace std;

const int Max = 100; 

struct Node {
    int info;
    Node* next;
};

struct hashTable {
    Node* first[Max] = {nullptr};
};

int hashModulus(int x) { return x % Max; }
int hashCutting(int x) { return x % 100; }
int hashFolding(int x) { return (x / 1000 + x % 1000) % Max; }

Node* createNode(int x) {
    return new Node{x, nullptr};
}

void insert(hashTable &h, int x, int (*hashFunc)(int)) {
    int index = hashFunc(x);
    Node* newNode = createNode(x);
    newNode->next = h.first[index];
    h.first[index] = newNode;
    cout << "Value " << x << " dimasukkan ke indeks " << index << endl;
}

void remove(hashTable &h, int x, int (*hashFunc)(int)) {
    int index = hashFunc(x);
    Node *P = h.first[index], *prev = nullptr;
    while (P && P->info != x) {
        prev = P;
        P = P->next;
    }
    if (!P) {
        cout << "Value " << x << " tidak ditemukan pada indeks " << index << endl;
        return;
    }
    if (!prev)
        h.first[index] = P->next;
    else
        prev->next = P->next;
    delete P;
    cout << "Value " << x << " dihapus dari indeks " << index << endl;
}

void display(const hashTable &h) {
    for (int i = 0; i < Max; ++i) {
        cout << "Indeks " << i << ": ";
        for (Node* P = h.first[i]; P; P = P->next)
            cout << P->info << " -> ";
        cout << "NULL" << endl;
    }
}

int main() {
    hashTable hMod, hCut, hFold;

    insert(hMod, 12345, hashModulus);
    insert(hCut, 12345, hashCutting);
    insert(hFold, 12345, hashFolding);
    insert(hMod, 67890, hashModulus);
    insert(hCut, 67890, hashCutting);
    insert(hFold, 67890, hashFolding);

    cout << "Tabel Hash dengan Modulus:\n";
    display(hMod);
    cout << "\nTabel Hash dengan Cutting:\n";
    display(hCut);
    cout << "\nTabel Hash dengan Folding:\n";
    display(hFold);

    remove(hMod, 12345, hashModulus);
    remove(hCut, 12345, hashCutting);
    remove(hFold, 12345, hashFolding);

    cout << "\nSetelah Penghapusan:\n";
    cout << "Tabel Hash dengan Modulus:\n";
    display(hMod);
    cout << "\nTabel Hash dengan Cutting:\n";
    display(hCut);
    cout << "\nTabel Hash dengan Folding:\n";
    display(hFold);

    return 0;
}
