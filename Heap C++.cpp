#include <iostream>
using namespace std;

#define max 10
#define nil 0

typedef int infotype;
typedef struct tHeap {
    infotype Data[max];
    infotype INDEX;
} Heap;

#define Data(H, i) (H).Data[i] 
#define INDEX(H) (H).INDEX

void CreateEmpty(Heap *H) {
    INDEX(*H) = nil;
    for (int i = 0; i < max; i++) { 
        Data(*H, i) = nil;
    }
}

bool IsEmpty(Heap H) {
    return (INDEX(H) == nil); 
}

bool IsFull(Heap H) {
    return (INDEX(H) == max);
}

void Heapify(Heap *H, infotype i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i; 
    if (left < INDEX(*H) && Data(*H, left) > Data(*H, largest)) {
        largest = left;
    }
    if (right < INDEX(*H) && Data(*H, right) > Data(*H, largest)) {
        largest = right;
    }
    if (largest != i) {
        int temp = Data(*H, i);
        Data(*H, i) = Data(*H, largest);
        Data(*H, largest) = temp;
        Heapify(H, largest);
    }
}

void Position(Heap *H, infotype j) {
    infotype t;
    int parent = (j - 1) / 2;
    if (Data(*H, parent) < Data(*H, j)) {
        t = Data(*H, parent);
        Data(*H, parent) = Data(*H, j);
        Data(*H, j) = t;

        if (parent != 0)
            Position(H, parent);
    }
}

void Insert(Heap *H, infotype x) {
    if (IsFull(*H)) {
        cout << "Heap penuh" << endl;
    } else {
        Data(*H, INDEX(*H)) = x;
        Position(H, INDEX(*H));
        INDEX(*H)++;
        cout << "Node " << x << " berhasil ditambah di index " << INDEX(*H) << endl;
    }
}

void Delete(Heap *H, infotype i) {
    if (IsEmpty(*H)) {
        cout << "Heap kosong" << endl;
        return;
    }
    if (i >= INDEX(*H)) {
        cout << "Indeks " << i << " tidak valid" << endl;
        return;
    }
    cout << "Node " << Data(*H, i) << " dihapus dari indeks " << i << endl;
    Data(*H, i) = Data(*H, INDEX(*H) - 1);
    INDEX(*H)--;
    Position(H, i); 
    Heapify(H, i);  
}

void Print(Heap H) {
    for (int i = 0; i < INDEX(H); i++) {
        cout << Data(H, i) << " ";
    }
    cout << endl;
}

int main() {
    Heap H;
    CreateEmpty(&H);
    Insert(&H, 10);
    Insert(&H, 7);
    Insert(&H, 7);
    Insert(&H, 1);
    Insert(&H, 3);
    Insert(&H, 2);
    Insert(&H, 4);
    cout << endl << "======" << endl;
    Print(H);
    cout << endl << "======" << endl;
    Insert(&H, 9);
    cout << endl;
    Print(H);
    cout << endl << "======" << endl;
    Delete(&H, 0); 
    Print(H);
    return 0;
}
