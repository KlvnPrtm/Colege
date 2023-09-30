#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;

} book;

int main(){

    struct Books Book1;
    
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali");
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    printf( "Book title : %s\n", Book1.title);
    printf( "Book author : %s\n", Book1.author);
    printf( "Book subject : %s\n", Book1.subject);
    printf( "Book book_id : %d\n", Book1.book_id);

    

}