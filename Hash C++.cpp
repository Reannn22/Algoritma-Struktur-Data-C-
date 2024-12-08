#include <iostream>
using namespace std;

#define max 100
#define nil 0

typedef int infotype;
typedef struct tNode *addrNode;

typedef struct tNode {
    infotype info;
    addrNode next;
} Node;

typedef struct tHash {
    addrNode first;
} Hash[max];

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(H, i) (H)[i].first

int HashModulus(infotype x) {
    return x % max;
}

int HashCutting(infotype x) {
    return x % 100;
}

int HashFolding(infotype x) {
    int part1 = x / 1000;
    int part2 = x % 1000;
    return (part1 + part2) % max;
}

void CreateEmptyHash(Hash H) {
    for (int i = 0; i < max; i++) {
        First(H, i) = nil;
    }
}

addrNode NodeAllocation(infotype x) {
    addrNode P = new Node;
    Info(P) = x;
    Next(P) = nil;
    return P;
}

void NodeDeAllocation(addrNode &P) {
    delete P;
    P = nil;
}

bool IsEmptyHash(Hash H, int index) {
    return First(H, index) == nil;
}

void Insert(Hash H, infotype x, int (*hashFunc)(infotype)) {
    int index = hashFunc(x);
    addrNode newNode = NodeAllocation(x);
    if (newNode != nil) {
        Next(newNode) = First(H, index);
        First(H, index) = newNode;
    }
    cout << "Value " << x << " dimasukkan ke indeks " << index << endl;
}

void Delete(Hash H, infotype x, int (*hashFunc)(infotype)) {
    int index = hashFunc(x);
    if (IsEmptyHash(H, index)) {
        cout << "Value " << x << " tidak ditemukan dalam tabel hash." << endl;
        return;
    }
    addrNode P = First(H, index);
    addrNode prev = nil;

    while (P != nil && Info(P) != x) {
        prev = P;
        P = Next(P);
    }
    if (P == nil) {
        cout << "Value " << x << " tidak ditemukan pada indeks " << index << endl;
        return;
    }
    if (prev == nil) {
        First(H, index) = Next(P);
    } else {
        Next(prev) = Next(P);
    }
    NodeDeAllocation(P);
    cout << "Value " << x << " dihapus dari indeks " << index << endl;
}

void Display(Hash H) {
    for (int i = 0; i < max; i++) {
        cout << "Indeks " << i << ": ";
        addrNode P = First(H, i);
        while (P != nil) {
            cout << Info(P) << " -> ";
            P = Next(P);
        }
        cout << "nil" << endl;
    }
}

int main() {
    Hash HMod, HCut, HFold;
    CreateEmptyHash(HMod);
    CreateEmptyHash(HCut);
    CreateEmptyHash(HFold);
    Insert(HMod, 12345, HashModulus);
    Insert(HCut, 12345, HashCutting);
    Insert(HFold, 12345, HashFolding);
    Insert(HMod, 67890, HashModulus);
    Insert(HCut, 67890, HashCutting);
    Insert(HFold, 67890, HashFolding);
    cout << "Tabel Hash dengan Modulus:" << endl;
    Display(HMod);
    cout << "\nTabel Hash dengan Cutting:" << endl;
    Display(HCut);
    cout << "\nTabel Hash dengan Folding:" << endl;
    Display(HFold);
    Delete(HMod, 12345, HashModulus);
    Delete(HCut, 12345, HashCutting);
    Delete(HFold, 12345, HashFolding);
    cout << "\nSetelah Penghapusan:" << endl;
    cout << "Tabel Hash dengan Modulus:" << endl;
    Display(HMod);
    cout << "\nTabel Hash dengan Cutting:" << endl;
    Display(HCut);
    cout << "\nTabel Hash dengan Folding:" << endl;
    Display(HFold);
    return 0;
}
