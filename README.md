# <h1 align="center">Laporan Praktikum Modul (7)</h1>
<p align="center">Mario Sebastian Barus</p>

## Dasar Teori
Stack adalah salah satu struktur data linear yang bekerja dengan prinsip last in first Out yang dimana fungsinya ialah  elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan melalui bagian yang disebut top Struktur data ini memiliki beberapa operasi dasar, seperti inisialisasi stack, penambahan elemen (push), penghapusan elemen (pop), pengecekan kondisi kosong atau penuh, serta penampilan isi data. Stack dapat diimplementasikan menggunakan array dengan kapasitas tertentu maupun linked list yang bersifat dinamis. Selain fungsi dasarnya, stack juga dapat dikembangkan dengan operasi tambahan, seperti push ascending untuk menjaga urutan data, reverse stack untuk membalik susunan elemen, serta pengolahan input stream dari pengguna. Seluruh variasi pengembangan tersebut tetap berlandaskan prinsip LIFO sehingga stack menjadi struktur data penting yang banyak dimanfaatkan dalam berbagai aplikasi pemrograman dan pengolahan data.
## Guided 

### stack.h
```C++

#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

//ubah kapasitas sesuai kebutuhan
using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
   
```

## Unguided 

### 1. [main1.cpp]

```C++
#include <iostream>
#include "stack1.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    initStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    showStack(S);

    cout << "Membalik stack" << endl;
    reverseStack(S);
    showStack(S);

    return 0;
}


```
Kode ini merupakan program utama yang digunakan untuk menjalankan dan menguji struktur data stack, mulai dari proses inisialisasi, penyisipan data secara terurut, hingga menampilkan dan membalik isi stack.
#### Full code Screenshot:
<img width="541" height="477" alt="image" src="https://github.com/user-attachments/assets/482a9866-7d16-40d5-9b3d-bf01f2fccb3b" />

### [stack1.cpp]

```C++
#include <iostream>
#include "stack1.h"
using namespace std;

void initStack(Stack &S) {
    S.topIndex = -1;
}

void pushItem(Stack &S, DataType value) {
    if (S.topIndex < 19) {
        S.topIndex++;
        S.items[S.topIndex] = value;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

DataType popItem(Stack &S) {
    if (S.topIndex >= 0) {
        DataType temp = S.items[S.topIndex];
        S.topIndex--;
        return temp;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void showStack(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.topIndex; i >= 0; i--) {
        cout << S.items[i] << " ";
    }
    cout << endl;
}

void reverseStack(Stack &S) {
    Stack temp;
    initStack(temp);

    while (S.topIndex >= 0) {
        pushItem(temp, popItem(S));
    }
    while (temp.topIndex >= 0) {
        pushItem(S, popItem(temp));
    }
}

void pushAscending(Stack &S, DataType value) {
    Stack temp;
    initStack(temp);

    while (S.topIndex >= 0 && S.items[S.topIndex] > value) {
        pushItem(temp, popItem(S));
    }

    pushItem(S, value);

    while (temp.topIndex >= 0) {
        pushItem(S, popItem(temp));
    }
}


```

Kode ini merupakan file implementasi fungsi stack yang mengatur proses inisialisasi, penyimpanan, penghapusan, penampilan, pembalikan, serta penyisipan data secara terurut menaik. Seluruh fungsi dirancang untuk memastikan pengelolaan data stack berjalan sesuai prinsip LIFO dan mendukung operasi manipulasi data secara efisien.
#### Full code Screenshot:
<img width="410" height="574" alt="image" src="https://github.com/user-attachments/assets/d0e9afb1-98b9-42bb-b802-d684b7f06ec2" />


### [stack1.h]

```C++
#ifndef STACK1_H
#define STACK1_H

typedef int DataType;

struct Stack {
    DataType items[20];
    int topIndex;
};

void initStack(Stack &S);
void pushItem(Stack &S, DataType value);
DataType popItem(Stack &S);
void showStack(const Stack &S);
void reverseStack(Stack &S);

void pushAscending(Stack &S, DataType value);

#endif


```

#### Output:
<img width="512" height="125" alt="image" src="https://github.com/user-attachments/assets/d1ec1b17-f4d3-4370-ac4c-f20c4474f8c2" />

Kode ini merupakan file header yang mendefinisikan struktur data stack beserta tipe data yang digunakan, sekaligus mendeklarasikan fungsi-fungsi utama untuk pengelolaan stack seperti inisialisasi, penyimpanan, penghapusan, penampilan, pembalikan, dan penyisipan data secara terurut.
#### Full code Screenshot:
<img width="446" height="358" alt="image" src="https://github.com/user-attachments/assets/a22d3c86-c3bc-4f52-9fd4-cb8f6a98ff50" />

### 2. [main2.cpp]

```C++
#include "stack2.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack s;
    createStack(s);

    pushAscending(s, 3);
    pushAscending(s, 4);
    pushAscending(s, 8);
    pushAscending(s, 2);
    pushAscending(s, 3);
    pushAscending(s, 9);

    printInfo(s);

    cout << "balik stack" << endl;
    balikStack(s);
    printInfo(s);

    return 0;
}


```
kode ini merupakan program utama yang digunakan untuk menjalankan dan menguji fungsi-fungsi stack melalui proses input dan output data.
#### Full code Screenshot:
<img width="442" height="456" alt="image" src="https://github.com/user-attachments/assets/6ce7c093-1d9c-45d5-b34e-42dc054c09da" />

### [stack2.cpp]

```C++
#include "stack2.h"

void createStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int x) {
    if (!isFull(s)) {
        s.top++;
        s.data[s.top] = x;
    }
}

void pop(Stack &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void pushAscending(Stack &s, int x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(s) && s.data[s.top] > x) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    push(s, x);

    while (!isEmpty(temp)) {
        push(s, temp.data[temp.top]);
        pop(temp);
    }
}

void printInfo(Stack s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &s) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(s)) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    s = temp;
}


```

kode ini memuat implementasi logika stack, termasuk proses penyusunan data secara ascending serta operasi pembalikan dan penampilan isi stack.
#### Full code Screenshot:
<img width="399" height="581" alt="image" src="https://github.com/user-attachments/assets/870879e5-9b7b-426b-a0a4-21a5aff8b217" />


### [stack2.h]

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int x);
void pop(Stack &s);
void pushAscending(Stack &s, int x);
void printInfo(Stack s);
void balikStack(Stack &s);

#endif




```

#### Output:
<img width="499" height="110" alt="image" src="https://github.com/user-attachments/assets/735602cd-3e47-46d2-b6e2-96b072f1fd73" />

File ini berisi pendefinisian struktur data stack serta deklarasi fungsi-fungsi dasar yang digunakan dalam pengelolaan data stack secara terurut.

#### Full code Screenshot:
<img width="384" height="456" alt="image" src="https://github.com/user-attachments/assets/8a16067f-e827-412f-a8df-129990534892" />

### 3. [main3.cpp]

```C++
#include "stack3.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}



```
Kode ini merupakan program utama yang berfungsi sebagai pengendali penggunaan struktur data stack, mulai dari proses pembuatan stack, penerimaan input data, penampilan isi stack, hingga pembalikan urutan stack untuk melihat hasil perubahan data.

#### Full code Screenshot:
<img width="367" height="321" alt="image" src="https://github.com/user-attachments/assets/ddb98bf0-75e2-4e21-a1a6-2f3bec88ce06" />

### [stack3.cpp]

```C++
#include "stack3.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if (S.top == MAX - 1) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (S.top == -1) {
        cout << "Stack Kosong!" << endl;
        return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        push(temp, pop(S));
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    createStack(S);

    char n;
    while (true) {
        n = cin.get();
        if (n == '\n') {
            break;
        }
        if (n >= '0' && n <= '9') {
            push(S, n - '0');
        }
    }
}


```

Kode ini merupakan file implementasi yang menangani seluruh proses kerja stack secara langsung, mulai dari membuat stack kosong, memasukkan dan mengeluarkan data, menampilkan isi stack, membalik urutan data, hingga menyisipkan elemen secara teratur dan membaca input dari pengguna.
#### Full code Screenshot:
<img width="264" height="533" alt="image" src="https://github.com/user-attachments/assets/c3c70a64-b9ad-4fba-8061-d0b2e2ccffab" />
<img width="318" height="272" alt="image" src="https://github.com/user-attachments/assets/bb08e743-b4ce-4ab1-bc7e-e73bf891c0f1" />


### [stack3.h]

```C++
#ifndef STACK3_H
#define STACK3_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);
void getInputStream(Stack &S);

#endif



```

#### Output:
<img width="510" height="129" alt="image" src="https://github.com/user-attachments/assets/eb4b623d-d04d-49c9-84f5-b5cbc39fd552" />

Kode ini merupakan file header yang digunakan sebagai acuan dalam pengelolaan struktur data stack. File ini memuat pendefinisian tipe data, batas kapasitas penyimpanan, serta daftar fungsi yang mendukung operasi stack, mulai dari inisialisasi, penambahan dan penghapusan elemen, penampilan data, pembalikan urutan, hingga pemrosesan input dan penyisipan data secara teratur.

#### Full code Screenshot:
<img width="402" height="457" alt="image" src="https://github.com/user-attachments/assets/344707e4-3892-4a60-b2a1-be9693d9b6e8" />





## Kesimpulan
Hasil pengamatan dan pembahasan teori menunjukkan bahwa stack adalah struktur data linear yang bekerja dengan prinsip Last In First Out (LIFO). Baik implementasi berbasis array maupun linked list sama-sama menerapkan operasi utama push dan pop pada bagian teratas stack. Stack berbasis array bersifat sederhana dengan kapasitas terbatas, sedangkan stack berbasis linked list lebih fleksibel karena dinamis. Pengembangan fitur seperti pengurutan ascending, pembalikan stack, dan pengolahan input menegaskan bahwa stack mudah disesuaikan dengan berbagai kebutuhan, sehingga memiliki peran penting dalam pemrograman.
## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
[2] Sahni, S. (2005). Data Structures, Algorithms, and Applications in C++. McGraw-Hill.
[3] Kadir, A. (2018). Algoritma dan Pemrograman Menggunakan C++. Andi Offset.
[4] Munir, R. (2016). Algoritma dan Struktur Data. Informatika Bandung.
