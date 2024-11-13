#include <iostream>
using namespace std;

#define max 5
#define min 0

typedef int infotype; // infotype akan didefinisikan sebagai integer (sebagai label)
typedef int address; // address didefinisikan sebagai integer (untuk alamat variabel)
typedef struct QueueElm{
    infotype Antrian[max + 1];
    address HEAD;
    address TAIL;
}Queue;
// BUAT DEKLARASI UNTUK MEMUDAHKAN INISIASI KODE PROGRAM HEAD, TAIL, INFO -> ADDRESS

#define head(Q) (Q).HEAD  // untuk posisi index head
#define tail(Q) (Q).TAIL // untuk posisi index tail
#define infoHead(Q) (Q).Antrian[(Q).HEAD]  // untuk posisi data dari index head
#define infoTail(Q) (Q).Antrian[(Q).TAIL] // untuk posisi data dari index tail

// setelah berhasil membuat blok struct untuk Queue
// sama seperti Stack kita membuat struct atau blok untuk mengisi data Queue (antrian)
// create empty Queue blok (dengan kondisi data antrian masih kosong)
// [], [], [], [], []
void CreateQueue(Queue *Q){
    head(*Q) = min;
    tail(*Q) = min;
}

/* fungsi untuk mengecek apakah blok stack Queue ini masih kosong dengan nilai
[head && tail], [], [], [], []
*/
bool IsEmpty(Queue Q){
    return ((head(Q) == min) && (tail(Q) == min));
}

// fungsi ini untuk menghitung jumlah elemen dalam queue
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

/* fungsi untuk mengecek apakah blok stack Queue ini sudah penuh atau tidak
[], [], [], [], [tail]
*/
bool IsFull(Queue Q){
    // return (tail(Q) == max);
    return (NbElmt(Q) == max);
}

// fungsi untuk add
void Add(Queue *Q, infotype X){
    if(IsFull(*Q)){
        cout<<"Stack Queue Penuh!!!!"<<endl;
    }else{
        if(IsEmpty(*Q)){  // jika kosong maka, head dan tail diatur ke 1
            head(*Q) = 1;
            tail(*Q) = 1;
        }else{
            tail(*Q)++; // jika tidak kosong, maka index tail akan ditambah
            // tail(*Q) = (tail(*Q) + 1) % (max + 1);
        }
        infoTail(*Q) = X; // data yang ditambhkan akan dimasukkan kedalam entri data infoTail
        cout<<"Data = "<<X<<" ditambahkan dalam Queue"<<endl;
    }
}

void Hapus(Queue *Q, infotype *hapus){
    //[5  ], [3 ->> head], [5], [3], [4];
    *hapus = infoHead(*Q); // 5
    if(IsEmpty(*Q)){
        cout<<"Queue kosong"<<endl;
    }else{
        cout<<"Data "<<*hapus<<" dihapus dari antrian"<<endl; // data 5 sudah dihapus
        if(head(*Q) == tail(*Q)){ // jika seandainya indeks head dan tail sama, maka diatur Queue ke kosong
            head(*Q) = min;
            tail(*Q) = min;
        }else{ // jika tidak sama, maka indekx posisi head, akan ditambah untuk berpindah
        // [5 ->head ], [3], [5], [3], [4];  ketika head dihapus
        // [ -> head], [3], [5], [3], [4]
        // --> pilihan satu
            if(head(*Q) == max){
                head(*Q) = 1;
            }else{
                head(*Q)++;// setelah melalui eksekusi ini, entri Queue menjadi : 
            // [3 -> head], [5], [3], [4 -> tail], [ ]
            }
        // --> pilihan dua
            // head(*Q) = (head(*Q) + 1) % (max + 1);
        }
    }
}

void ShowData(Queue *Q){
    if(IsEmpty(*Q)){
        cout<<"Queue kosong"<<endl;
    }else{
        cout<<"Data dalam Queue : ";
        // menampilkan entri data dari posisi index head sampai tail
        // [3 -> head], [5], [3], [4 -> tail], [ ]
        for(int i = head(*Q); i <= tail(*Q); i++){
            cout<<(*Q).Antrian[i]<<" ";
        }
        cout << endl;
    }
}

int main(){
    Queue Q;
    infotype hapus;

    // kita membua stack kosong
    CreateQueue(&Q);

    // kita menambahkan data
    // [5 ->head ], [3], [5], [3], [4];
    Add(&Q, 5);  // menambah 5
    Add(&Q, 3); // menambah 3
    Add(&Q, 8);
    Add(&Q, 10);
    Add(&Q, 4);
    Add(&Q, 10);
    cout<<"----------------"<<endl;
    ShowData(&Q);
    
    cout<<"------"<<endl;
    Hapus(&Q, &hapus);
    ShowData(&Q);
    // kita coba mau nampilkan
    // Hapus(&Q, &hapus);
    // Hapus(&Q, &hapus);
    // Hapus(&Q, &hapus);
    // ShowData(&Q);

    // Add(&Q, 11);
    // // ShowData(&Q);

    // cout<<"----------------"<<endl;

    return 0;
}
