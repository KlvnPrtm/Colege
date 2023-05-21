#ifdef _WIN32
#include <windows.h>
#define clear() system("cls")
#else
#include <unistd.h>
#define clear() system("clear")

#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nama[50];
    char alamat[100];
    long int saldo;
} Nasabah;

typedef struct Node {
    Nasabah data;
    struct Node* next;
} Node;

Node* head = NULL;
int id_counter = 1;

// Fungsi untuk menambahkan data nasabah ke linked list
void tambahNasabah() {
    Nasabah nasabah;
    nasabah.id = id_counter;
    printf("Masukkan nama nasabah: ");
    scanf("%s", nasabah.nama);
    printf("Masukkan alamat nasabah: ");
    scanf("%s", nasabah.alamat);
    printf("Masukkan saldo nasabah: ");
    scanf("%ld", &nasabah.saldo);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = nasabah;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* curr_node = head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }

    printf("Nasabah dengan ID %d berhasil ditambahkan.\n", nasabah.id);
    id_counter++;
}

// Fungsi untuk menampilkan data nasabah dari linked list
void tampilkanNasabah() {
    if (head == NULL) {
        printf("Tidak ada nasabah yang terdaftar.\n");
        return;
    }

    Node* curr_node = head;
    printf("%-5s %-20s %-50s %-20s\n", "ID", "Nama", "Alamat", "Saldo");
    while (curr_node != NULL) {
        printf("%-5d %-20s %-50s %-20ld\n", curr_node->data.id, curr_node->data.nama, curr_node->data.alamat, curr_node->data.saldo);
        curr_node = curr_node->next;
    }
}

// Fungsi untuk mengubah data nasabah dari linked list
void ubahNasabah() {
    int id;
    printf("Masukkan ID nasabah yang ingin diubah: ");
    scanf("%d", &id);

    Node* target_node = NULL;
    Node* curr_node = head;
    while (curr_node != NULL) {
        if (curr_node->data.id == id) {
            target_node = curr_node;
            break;
        }
        curr_node = curr_node->next;
    }

    if (target_node == NULL) {
        printf("Nasabah dengan ID %d tidak ditemukan.\n", id);
        return;
    }

    Nasabah nasabah;
    nasabah.id = target_node->data.id;
    printf("Masukkan nama nasabah baru: ");
    scanf("%s", nasabah.nama);
    printf("Masukkan alamat nasabah baru: ");
    scanf("%s", nasabah.alamat);
    printf("Masukkan saldo nasabah baru: ");
    scanf("%ld", &nasabah.saldo);

    target_node->data = nasabah;
    printf("Data nasabah dengan ID %d telah diubah.\n", id);
}

// Fungsi untuk menghapus data nasabah dari linked list
void hapusNasabah() {
    int id;
// Meminta input dari user untuk ID nasabah yang ingin dihapus
	printf("Masukkan ID nasabah yang ingin dihapus: ");
	scanf("%d", &id);
	Node* target_node = NULL;
	Node* prev_node = NULL;
	Node* curr_node = head;
	while (curr_node != NULL) {
    	if (curr_node->data.id == id) {
        	target_node = curr_node;
        	break;
    	}
    	prev_node = curr_node;
    	curr_node = curr_node->next;
	}

	if (target_node == NULL) {
    	printf("Nasabah dengan ID %d tidak ditemukan.\n", id);
    	return;
	}

	if (target_node == head) {
    	head = target_node->next;
	} else {
    	prev_node->next = target_node->next;
	}

	free(target_node);
	printf("Nasabah dengan ID %d berhasil dihapus.\n", id);
	}

int main() {
	int choice;
	while (1) {
    printf("Menu:\n");
    printf("1. Tambah Nasabah\n");
    printf("2. Tampilkan Nasabah\n");
    printf("3. Ubah Nasabah\n");
    printf("4. Hapus Nasabah\n");
    printf("5. Keluar\n");
    printf("Pilih opsi (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        	clear();
            tambahNasabah();
            break;
        case 2:
        	clear();
            tampilkanNasabah();
            break;
        case 3:
        	clear();
            ubahNasabah();
            break;
        case 4:
        	clear();
            hapusNasabah();
            break;
        case 5:
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
    printf("\n");
	}

	return 0;
}


