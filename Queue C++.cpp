#include <iostream>
using namespace std;

#define max 10
#define nil 0

typedef int infotype;
typedef int address;

typedef struct DataQueue{
    infotype Data [max + 1];
    address FRONT,REAR;
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
    return (FRONT(Q) == max);
}

bool IsEmpty(queue Q){
    return (REAR(Q) == nil);
}

void Enqueue(queue *Q, infotype X){
    if(!IsFull(*Q)){
        if(IsEmpty(*Q)){
            FRONT(*Q) = 1;
        }
        REAR(*Q) += 1;
        InfoRear(*Q) = X;
        cout<<"Data "<<X<<" berhasil ditambah"<<endl;
    } else {
        cout<<"Data penuh"<<endl;
    }
}

void Dequeue(queue *Q, infotype *X){
    if(!IsEmpty(*Q)){
        *X = InfoFront(*Q);
        if(FRONT(*Q) == REAR(*Q)){
            FRONT(*Q) = nil;
            REAR(*Q) = nil;
        } else {
            FRONT(*Q) += 1;
        }
        cout<<"Data "<<*X<<" berhasil dihapus"<<endl;
    } else {
        cout<<"Data kosong"<<endl;
    }
}

void ShowData(queue *Q){
    if(!IsEmpty(*Q)){
        for(int i = FRONT(*Q); i <= REAR(*Q); i++){
            cout<<(*Q).Data[i]<<endl;
        }
    } else {
        cout<<"Data Kosong"<<endl;
    }
}

int main(){
    queue DataAntrianQueue;
    infotype Data;
    CreateEmpty(&DataAntrianQueue);
    Enqueue(&DataAntrianQueue, 3);
    Enqueue(&DataAntrianQueue, 4);
    Enqueue(&DataAntrianQueue, 5);
    ShowData(&DataAntrianQueue);
    Dequeue(&DataAntrianQueue, &Data);
    ShowData(&DataAntrianQueue);
    return 0;
}
