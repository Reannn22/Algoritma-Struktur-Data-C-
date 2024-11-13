#include <iostream>
using namespace std;

// kode untuk membuat struct 
#define max 10
#define nil 0

typedef int infotype; //infotype itu untuk tipe data  merujuk ke nilai;
typedef int address; // address itu untuk tipe data merujuk ke alamat nilai tersebut

typedef struct DataStack{
    infotype Data[max + 1]; // Data[10+ 1] = [][][][][]  < 10 || <= 10
    address TOP;
}stack;

#define TOP(S) (S).TOP  // untuk indeks data
#define InfoTop(S) (S).Data[(S).TOP]  // untuk nilai data

void CreateEmpty(stack *S){
    TOP(*S) = nil; // mengatur bagan stack dalam keadaan kosong
}
// {[], [], []. []. []. []. []. []. []. []}
bool IsFull(stack S){
    // mengembalikan true dan false
    // berdasarkan kondisi di return
    return (TOP(S) == max);
}
bool IsEmpty(stack S){
    return (TOP(S) == nil);
}

void Push(stack *S, infotype X){
    if(!IsFull(*S)){
        TOP(*S)+=1;
        
        InfoTop(*S) = X;
        cout<<"Data "<<X<<" berhasil ditambah"<<endl;
    }else{
        cout<<"Data dalam stack itu penuh!!"<<endl;
    }
}

void Pop(stack *S, address *X){ // pop ini untuk menghapus
    if(!IsEmpty(*S)){
        *X = InfoTop(*S); // akan menyimpan alamat dari TOP data nya
        TOP(*S)-=1; // akan menghapus index dari TOP
        cout<<"Data "<<*X<<" berhasil Dihapus"<<endl;
    }else{
        cout<<"Data kosong, tidak yang bisa dihapus"<<endl;
    }
}
// coba membuat fungsi yang menampilkan Data antrian 
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
    
    CreateEmpty(&DataStackAntrian); // in merujuk ke alamat  index setiap kolom bagan stack kita
    
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
