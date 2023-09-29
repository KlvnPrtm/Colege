#include <stdio.h>
#include <ctype.h>

int main(void) {
  int choice; // variable to store the user's choice
  char input[10]; // variable to store the user's input as a string
  int valid; // variable to check if the input is valid or not

  do {
    printf("Welcome to the simple menu\n");
    printf("Please choose one of the following options:\n");
    printf("1. Say hello\n");
    printf("2. Say goodbye\n");
    printf("3. Exit\n");
    printf("Your choice: ");

    scanf("%s", input); // read the user's input as a string
    valid = 1; // assume the input is valid by default

    // check if the input is a single digit
    if (strlen(input) == 1 && (input[0])) {
      choice = input[0] - '0'; // convert the input to an integer
    } else {
      valid = 0; // the input is not valid
    }

    // check if the input is within the range of options
    if (choice < 1 || choice > 3) {
      valid = 0; // the input is not valid
    }

    // handle the input based on its validity
    if (valid) {
      // the input is valid, use if else statements to execute the menu logic
      if (choice == 1) {
        printf("Hello, nice to meet you!\n");
      } else if (choice == 2) {
        printf("Goodbye, have a nice day!\n");
      } else if (choice == 3) {
        printf("Thank you for using the simple menu. See you next time!\n");
      }
    } else {
      // the input is not valid, show an error message and ask the user to try again
      printf("Invalid input. Please enter a number between 1 and 3.\n");
    }
  } while (choice != 3); // repeat the menu until the user chooses to exit

  return 0;
}