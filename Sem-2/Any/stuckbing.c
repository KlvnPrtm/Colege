#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input;

// Mendefinisikan tipe data struct untuk stack
typedef struct stack {
    int top; // menyimpan indeks elemen teratas
    int data[3]; // menyimpan elemen-elemen stack
} stack;

// Membuat fungsi untuk mengecek apakah stack kosong
int isEmpty(stack *s) {
    return (s->top == -1); // jika top = -1, berarti stack kosong
}

// Membuat fungsi untuk mengecek apakah stack penuh
int isFull(stack *s) {
    return (s->top == 2); // jika top = 2, berarti stack penuh karena maksimal 3 elemen
}

// Membuat fungsi untuk menambahkan elemen ke dalam stack (push)
void push(stack *s, char x) {
    if (isFull(s)) { // jika stack penuh, tidak bisa push
        printf("Stack sudah penuh!\n");
    } else { // jika tidak penuh, tambahkan elemen ke atas stack dan naikkan top
        s->top++;
        s->data[s->top] = x;
        printf("Data %c berhasil dimasukkan ke dalam stack.\n", x);
    }
}

// Membuat fungsi untuk mengeluarkan elemen dari dalam stack (pop)
int pop(stack *s) {
    if (isEmpty(s)) { // jika stack kosong, tidak bisa pop
        printf("Stack sudah kosong!\n");
        return -1;
    } else { // jika tidak kosong, ambil elemen teratas dari stack dan turunkan top
        char x = s->data[s->top];
        s->top--;
        printf("Data %c berhasil dikeluarkan dari dalam stack.\n", x);
        return x;
    }
}

// Membuat fungsi untuk menampilkan isi stack dari atas ke bawah
void display(stack *s) {
    if (isEmpty(s)) { // jika stack kosong, tidak ada yang ditampilkan
        printf("Stack kosong!\n");
    } else { // jika tidak kosong, tampilkan semua elemen mulai dari atas sampai bawah
        printf("Isi Stack: \n");
        for (int i = s->top; i >= 0; i--) {
            printf("%c\n", s->data[i]);
        }
    }
}

// Fungsi utama program
int main() {
    
    // Membuat variabel untuk menyimpan pilihan menu dan inputan user 
    int menu;
    
    // Membuat variabel bertipe struct stack dan menginisialisasi top dengan -1 
    struct stack s;
    s.top = -1;

    do {
        
        // Menampilkan menu operasi pada user 
        printf("\nMenu Operasi Stack: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        // Meminta user memasukkan pilihan menu 
        printf("Masukkan pilihan anda: ");
        
		// Mengambil inputan user sebagai pilihan menu 
		scanf("%d", &menu);

		// Melakukan operasi sesuai dengan pilihan menu 
		switch(menu) {

			case 1: // Jika user memilih push 
				printf("\nMasukkan data yang ingin dimasukkan ke dalam Stack: ");
				scanf(" %[^\n]", &input); // Mengambil inputan user sebagai data yang akan di-push 
				push(&s, input); // Memanggil fungsi push dengan parameter alamat variabel s dan inputan user 
				break;

			case 2: // Jika user memilih pop 
				pop(&s); // Memanggil fungsi pop dengan parameter alamat variabel s  
				break;
            case 3:
                display(&s);

        }
    }
    while (2);
    
}