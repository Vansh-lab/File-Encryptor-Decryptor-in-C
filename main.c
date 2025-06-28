#include <stdio.h>
#include <stdlib.h>

void encrypt_file(const char *input, const char *output, int key) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (!fin || !fout) {
        printf(" Error opening files.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z')) {
            ch = ((ch - 'A' + key) % 26) + 'A';
        } else if ((ch >= 'a' && ch <= 'z')) {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);
    printf(" File encrypted to '%s'\n", output);
}

void decrypt_file(const char *input, const char *output, int key) {
    encrypt_file(input, output, 26 - (key % 26)); // Caesar reverse
    printf(" File decrypted to '%s'\n", output);
}

int main() {
    int choice, key;
    char infile[100], outfile[100];

    while (1) {
        printf(" File Encryptor/Decryptor .\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("0. Exit\n");
        printf("Choose:\n ");
        scanf("%d", &choice);

        if (choice == 0) break;

        printf("Enter input file name:\n ");
        scanf("%s", infile);
        printf("Enter output file name: \n");
        scanf("%s", outfile);
        printf("Enter key (number): \n");
        scanf("%d", &key);

        if (choice == 1)
            encrypt_file(infile, outfile, key);
        else if (choice == 2)
            decrypt_file(infile, outfile, key);
        else
            printf(" Invalid choice.\n");
return 0;
}
}
