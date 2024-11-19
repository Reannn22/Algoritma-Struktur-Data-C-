#include <iostream>
using namespace std;

#define max 10
#define nil 0

typedef int infotype; 
typedef int address; 

typedef struct DataQueue{
    infotype Data[max + 1]; 
    address FRONT, REAR;
}queue;

#define FRONT(Q) (Q).FRONT  
#define REAR(Q) (Q).REAR  
#define InfoFront(Q) (Q).Data[(Q).FRONT] 
#define InfoRear(Q) (Q).Data[(Q).REAR]

void CreateEmpty(queue *Q){
    FRONT(*Q) = nil;
    REAR(*Q) = nil;
}

bool IsFull(queue Q){
    return (REAR(Q) == max);
}

bool IsEmpty(queue Q){
    return (FRONT(Q) == nil);
}

void Enqueue(queue *Q, infotype X){
    if(!IsFull(*Q)){
        if(IsEmpty(*Q)){
            FRONT(*Q) = 1;  
        }
        REAR(*Q) += 1;
        InfoRear(*Q) = X;
        cout << "Data " << X << " berhasil ditambah" << endl;
    } else {
        cout << "Antrian penuh!" << endl;
    }
}

void Dequeue(queue *Q, address *X){
    if(!IsEmpty(*Q)){
        *X = InfoFront(*Q);
        if(FRONT(*Q) == REAR(*Q)){
            FRONT(*Q) = nil;
            REAR(*Q) = nil;
        } else {
            FRONT(*Q) += 1;
        }
        cout << "Data " << *X << " berhasil dihapus" << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void ShowData(queue *Q){
    if(!IsEmpty(*Q)){
        cout << "Data dalam antrian = " << endl;
        for(int i = FRONT(*Q); i <= REAR(*Q); i++){
            cout << (*Q).Data[i] << endl;
        }
    } else {
        cout << "Antrian kosong" << endl;
    }
}

int main(){
    queue DataQueueAntrian;
    infotype Data;
    CreateEmpty(&DataQueueAntrian);
    Enqueue(&DataQueueAntrian, 2);
    Enqueue(&DataQueueAntrian, 3);
    Enqueue(&DataQueueAntrian, 1);
    Enqueue(&DataQueueAntrian, 4);
    ShowData(&DataQueueAntrian);
    Dequeue(&DataQueueAntrian, &Data);
    ShowData(&DataQueueAntrian);
    
    return 0;
}
