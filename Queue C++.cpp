#include <iostream>
using namespace std;

#define max 5
#define min 0

typedef int infotype; 
typedef int address; 
typedef struct QueueElm{
    infotype Antrian[max + 1];
    address HEAD;
    address TAIL;
}Queue;

#define head(Q) (Q).HEAD  
#define tail(Q) (Q).TAIL 
#define infoHead(Q) (Q).Antrian[(Q).HEAD]  
#define infoTail(Q) (Q).Antrian[(Q).TAIL] 

void CreateQueue(Queue *Q){
    head(*Q) = min;
    tail(*Q) = min;
}

bool IsEmpty(Queue Q){
    return ((head(Q) == min) && (tail(Q) == min));
}

int NbElmt(Queue Q){
    if (IsEmpty(Q)){
        return 0;
    }else{
        if(head(Q) <= tail(Q)){
            return (tail(Q) - head(Q) + 1);
        }else{
            return (max - head(Q) + tail(Q) + 1);
        }
    }
}

bool IsFull(Queue Q){
    return (NbElmt(Q) == max);
}

void Add(Queue *Q, infotype X){
    if(IsFull(*Q)){
        cout<<"Stack Queue Penuh!!!!"<<endl;
    }else{
        if(IsEmpty(*Q)){ 
            head(*Q) = 1;
            tail(*Q) = 1;
        }else{
            tail(*Q)++; 
        }
        infoTail(*Q) = X; 
        cout<<"Data = "<<X<<" ditambahkan dalam Queue"<<endl;
    }
}

void Hapus(Queue *Q, infotype *hapus){
    *hapus = infoHead(*Q); 
    if(IsEmpty(*Q)){
        cout<<"Queue kosong"<<endl;
    }else{
        cout<<"Data "<<*hapus<<" dihapus dari antrian"<<endl;
        if(head(*Q) == tail(*Q)){ 
            head(*Q) = min;
            tail(*Q) = min;
        }else{ 
            if(head(*Q) == max){
                head(*Q) = 1;
            }else{
                head(*Q)++;
            }
        }
    }
}

void ShowData(Queue *Q){
    if(IsEmpty(*Q)){
        cout<<"Queue kosong"<<endl;
    }else{
        cout<<"Data dalam Queue : ";
        for(int i = head(*Q); i <= tail(*Q); i++){
            cout<<(*Q).Antrian[i]<<" ";
        }
        cout << endl;
    }
}

int main(){
    Queue Q;
    infotype hapus;
    CreateQueue(&Q);
    Add(&Q, 5); 
    Add(&Q, 3); 
    Add(&Q, 8);
    Add(&Q, 10);
    Add(&Q, 4);
    Add(&Q, 10);
    cout<<"----------------"<<endl;
    ShowData(&Q);
    cout<<"------"<<endl;
    Hapus(&Q, &hapus);
    ShowData(&Q);
    return 0;
}
