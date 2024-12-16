#include <iostream>
using namespace std;

const int MAX = 100; 

struct Node {
    int info;
    Node* next;
};

struct HashTable {
    Node* first[MAX];
};

int hashModulus(int x) {
    return x % MAX;
}

int hashCutting(int x) {
    return x % 100;
}

int hashFolding(int x) {
    int part1 = x / 1000;
    int part2 = x % 1000;
    return (part1 + part2) % MAX;
}

void createEmptyHash(HashTable &H) {
    for (int i = 0; i < MAX; i++) {
        H.first[i] = NULL;
    }
}

Node* alloc(int x) {
    Node* newNode = new Node;
    newNode->info = x;
    newNode->next = NULL;
    return newNode;
}

void dealloc(Node* &P) {
    delete P;
    P = NULL;
}

bool isEmptyHash(HashTable &H, int index) {
    return H.first[index] == NULL;
}

void insert(HashTable &H, int x, int (*hashFunc)(int)) {
    int index = hashFunc(x);
    Node* newNode = alloc(x);
    if (newNode) {
        newNode->next = H.first[index];
        H.first[index] = newNode;
    }
    cout << "Value " << x << " dimasukkan ke indeks " << index << endl;
}

void remove(HashTable &H, int x, int (*hashFunc)(int)) {
    int index = hashFunc(x);
    Node* P = H.first[index];
    Node* prev = NULL;
    while (P && P->info != x) {
        prev = P;
        P = P->next;
    }
    if (!P) {
        cout << "Value " << x << " tidak ditemukan pada indeks " << index << endl;
        return;
    }
    if (!prev) {
        H.first[index] = P->next;
    } else {
        prev->next = P->next;
    }
    dealloc(P);
    cout << "Value " << x << " dihapus dari indeks " << index << endl;
}

void display(const HashTable &H) {
    for (int i = 0; i < MAX; i++) {
        cout << "Indeks " << i << ": ";
        Node* P = H.first[i];
        while (P) {
            cout << P->info << " -> ";
            P = P->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    HashTable HMod, HCut, HFold;
    createEmptyHash(HMod);
    createEmptyHash(HCut);
    createEmptyHash(HFold);

    insert(HMod, 12345, hashModulus);
    insert(HCut, 12345, hashCutting);
    insert(HFold, 12345, hashFolding);
    insert(HMod, 67890, hashModulus);
    insert(HCut, 67890, hashCutting);
    insert(HFold, 67890, hashFolding);

    cout << "Tabel Hash dengan Modulus:" << endl;
    display(HMod);
    cout << "\nTabel Hash dengan Cutting:" << endl;
    display(HCut);
    cout << "\nTabel Hash dengan Folding:" << endl;
    display(HFold);

    remove(HMod, 12345, hashModulus);
    remove(HCut, 12345, hashCutting);
    remove(HFold, 12345, hashFolding);

    cout << "\nSetelah Penghapusan:" << endl;
    cout << "Tabel Hash dengan Modulus:" << endl;
    display(HMod);
    cout << "\nTabel Hash dengan Cutting:" << endl;
    display(HCut);
    cout << "\nTabel Hash dengan Folding:" << endl;
    display(HFold);

    return 0;
}
