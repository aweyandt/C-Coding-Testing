#include <stdio.h>
#include <stdlib.h>

void exit_status(int status) {
    if (status == 0) {
        printf("File is displayed\n");
    } else if (status == 1) {
        printf("Error opening file\n");
    }
}

int main() {
    FILE *fptr; // Declare file pointer

    fptr = fopen("testfile.txt", "r"); // Opens file in read mode ("r")

    // Check if file was opened successfully
    if (fptr == NULL) {
        // If fopen failed (file not found or cannot be opened), print the error message
        exit_status(1); // Exit with status 1
    } else {
        // File opened successfully
        exit_status(0); // Exit with status 0
        fclose(fptr); // Close the file after use
    }

    return 0;
}
