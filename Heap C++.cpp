#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(vector<int>& heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;
    if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        largest = leftChild;
    if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        largest = rightChild;
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(vector<int>& heap, int value) {
    heap.push_back(value); 
    heapifyUp(heap, heap.size() - 1); 
}

void deleteRoot(vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap kosong!" << endl;
        return;
    }
    heap[0] = heap.back(); 
    heap.pop_back(); 
    heapifyDown(heap, 0);
}

void displayHeap(const vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> maxHeap;
    
    insert(maxHeap, 50); 
    insert(maxHeap, 30); 
    insert(maxHeap, 20); 
    insert(maxHeap, 40); 
    insert(maxHeap, 10);

    cout << "Isi heap setelah insert: ";
    displayHeap(maxHeap);
    cout<<endl;

    cout << "Layani pasien dengan prioritas tertinggi...\n";
    deleteRoot(maxHeap);
    cout << "Isi heap setelah delete: ";
    displayHeap(maxHeap);
    cout<<endl;

    cout << "Tambahkan pasien baru dengan prioritas 45...\n";
    insert(maxHeap, 45);
    cout << "Isi heap setelah insert baru: ";
    displayHeap(maxHeap);
    cout<<endl;

    return 0;
}
