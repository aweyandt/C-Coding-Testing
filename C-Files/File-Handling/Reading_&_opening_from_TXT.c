#include <stdio.h>
#include <stdlib.h>

void exit_status(int status) {
    if (status == 0) {
        printf("Testfile works\n");
    } else if (status == 1) {
        printf("File Failed\n");  // Corrected typo
    }
}

int main() {
    FILE *file_pointer; // Declare file pointer

    file_pointer = fopen("testfile.txt", "r"); // Opens file in read mode ("r")

    char data_read[70];

    // Check if file was opened successfully
    if (file_pointer == NULL) {
        // If fopen failed (file not found or cannot be opened), print the error message
        exit_status(1); // Exit with status 1
        return 1;  // Return an error code to indicate failure
    } else {
        // File opened successfully
        exit_status(0); // Exit with status 0

        while(fgets(data_read, sizeof(data_read), file_pointer) != NULL){
            printf("%s", data_read);
        }

        fclose(file_pointer); // Always close the file when done
    }

    return 0;
}
