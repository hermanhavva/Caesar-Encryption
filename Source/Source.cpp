#include <windows.h>
#include <iostream>
#include <stdio.h>

//using namespace std; 

/*
char* Encrypt(char* messageToEncrypt, int offSet);
char* Decrypt(char* messageToDecrypt, int offSet);
*/
// Function pointers
typedef char*(*encrypt_ptr_t)(char*, int);
typedef char* (*decrypt_ptr_t)(char*, int);
// Const dll function naming
const char* encryptProcName = "EncryptStr";
const char* decryptProcName = "DecryptStr";
// Const input size
const int INPUTSIZE = 201;
// Function declaration
int HandleEncrypt(char*, encrypt_ptr_t);
int HandleDecrypt(char*, decrypt_ptr_t);


int main() 
{
    HINSTANCE handle = LoadLibrary(TEXT("..\\..\\Source\\caesarDLL\\x64\\Debug\\caesarDLL.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) 
    {
        printf("Lib not found\n");
        return 1;
    } 

    encrypt_ptr_t encryptProcPtr = (encrypt_ptr_t)GetProcAddress(handle, encryptProcName);
   
    if (encryptProcName == nullptr) 
    {
        printf("Function not found\n");
        FreeLibrary(handle);
        return 1;
    }

    decrypt_ptr_t decryptProcPtr = (decrypt_ptr_t)GetProcAddress(handle, decryptProcName);
    
    if (decryptProcPtr == nullptr) 
    {
        printf("Function not found\n");
        FreeLibrary(handle);
        return 1; 
    }

    char* input = new char[INPUTSIZE];
    bool ifContinue = true;

    while (ifContinue)
    { 
        printf("Exit - 0; Encrypt - 1; Decrypt - 2;\n");
        char commandCode;
        scanf_s("%c", &commandCode, 1);
        while ((getchar()) != '\n');  // to remove '\n' from stdin

        int key = 0;

        switch (commandCode)
        {
        case '0':
            ifContinue = false;
            break;
        case '1':
            HandleEncrypt(input, encryptProcPtr);
            break;
        case '2':
            HandleDecrypt(input, decryptProcPtr);
            break;
        default:
            printf("Command not implemented\n");
            break;
        }
    }
    delete[] input; 
    FreeLibrary(handle);

    return 0;
    
}

int HandleEncrypt(char* input, encrypt_ptr_t encryptProcPtr)
{
    int key = 0;
    
    printf("Enter str to encrypt:\n");
    fgets(input, INPUTSIZE, stdin);

    printf("Enter the key:\n");
    scanf_s("%d", &key);
    while ((getchar()) != '\n');  // to remove '\n' from stdin

    if (key > 26 || key < -26) {
        printf("The key is too big\n");
        return -1;
    }
    encryptProcPtr(input, key);
    printf("Encrypted message is: %s", input);

    return 0;
}

int HandleDecrypt(char* input, decrypt_ptr_t decryptProcPtr)
{
    int key = 0;

    printf("Enter str to decrypt:\n");
    fgets(input, INPUTSIZE, stdin);

    printf("Enter the key:\n");
    scanf_s("%d", &key);
    while ((getchar()) != '\n');  // to remove '\n' from stdin

    if (key > 26 || key < -26) {
        printf("The key is too big\n");
        return -1;
    }
    decryptProcPtr(input, key);
    printf("Decrypted message is: %s", input);

    return 0;
}