#include <iostream>
using namespace std;

#define max 10
#define nil 0

typedef int infotype; 
typedef int address; 

typedef struct DataStack{
    infotype Data[max + 1]; 
    address TOP;
}stack;

#define TOP(S) (S).TOP  
#define InfoTop(S) (S).Data[(S).TOP] 

void CreateEmpty(stack *S){
    TOP(*S) = nil; 
}

bool IsFull(stack S){
    return (TOP(S) == max);
}

bool IsEmpty(stack S){
    return (TOP(S) == nil);
}

void Push(stack *S, infotype X){
    if(!IsFull(*S)){
        InfoTop(*S) = X;
        TOP(*S)+=1;
        cout<<"Data "<<X<<" berhasil ditambah"<<endl;
    }else{
        cout<<"Data dalam stack itu penuh!!"<<endl;
    }
}

void Pop(stack *S, address *X){ 
    if(!IsEmpty(*S)){
        *X = InfoTop(*S); 
        TOP(*S)-=1;
        cout<<"Data "<<*X<<" berhasil dihapus"<<endl;
    }else{
        cout<<"Data dalam stack itu kosong!!"<<endl;
    }
}

void ShowData(stack *S){
    if(!IsEmpty(*S)){
        cout<<"Data dalam stack = "<<endl;
        for(int i = TOP(*S); i >= 1; i--){
            cout<<(*S).Data[i]<<endl;
        }
    }else{
        cout<<"Data kosong"<<endl;
    }
    
}

int main(){
    stack DataStackAntrian;
    infotype Data;
    CreateEmpty(&DataStackAntrian);
    cout<<"--->Menambah data-----<"<<endl;;
    Push(&DataStackAntrian, 3);
    Push(&DataStackAntrian, 5);
    Push(&DataStackAntrian, 8);
    Push(&DataStackAntrian, 7);
    Push(&DataStackAntrian, 4);
    cout<<endl;
    cout<<"--->Menampilkan data-----<"<<endl;;
    ShowData(&DataStackAntrian);
    cout<<endl;
    cout<<"--->Menghapus data-----<"<<endl;;
    Pop(&DataStackAntrian, &Data);
    Pop(&DataStackAntrian, &Data);
    cout<<endl;
    cout<<"--->Menampilkan data-----<"<<endl;;
    ShowData(&DataStackAntrian);
    return 0;
}
