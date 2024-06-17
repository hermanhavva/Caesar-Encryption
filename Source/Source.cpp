// MathClient.cpp : Client app for MathLibrary DLL.
 //#include "pch.h" //Uncomment for Visual Studio 2017 and earlier
#include <windows.h>
#include <iostream>
//#include "caesar.h"
using namespace std; 


char* Encrypt(char* messageToEncrypt, int offSet);
char* Decrypt(char* messageToDecrypt, int offSet);
// Pointer to sum function
typedef double(*sum_ptr_t)(double, double);
// Pointer to multiply function
typedef double(*multiply_ptr_t)(double, double);
 
int main() {
 
    char message[] = "Xy13Z";

   
    Encrypt(message, 1);
    cout << message << endl;  // the key is no more than 26 
    Decrypt(message, 1);
    cout << message << endl;

    /*   HINSTANCE handle = LoadLibrary(TEXT("..\\caesarDLL\\x64\\Debug\\caesarDLL.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
        cout << "Lib not found" << endl;
        return 1;
    } 

    sum_ptr_t sum_ptr = (sum_ptr_t)GetProcAddress(handle, "sum");
    if (sum_ptr == nullptr) {
        cout << "Function not found" << endl;
        FreeLibrary(handle);
        return 1;
    }

    multiply_ptr_t multiply_ptr = (multiply_ptr_t)GetProcAddress(handle, "multiply");
    if (multiply_ptr == nullptr) {
        cout << "Function not found" << endl;
        FreeLibrary(handle);
        return 1; 
    }

    cout << sum_ptr(4, 5) << endl;
    cout << multiply_ptr(6, 3) << endl;

    FreeLibrary(handle);
    return 0;
    */
}
char* Encrypt(char* messageToEncrypt, int offSet)
{

    for (int index = 0; index <= strlen(messageToEncrypt); index++)
    {
        int curChCodeWithOffSet = (int)messageToEncrypt[index] + offSet;


        if ((int)messageToEncrypt[index] >= (int)('A') && (int)messageToEncrypt[index] <= (int)('Z'))  // uppercase letter
        {
            if (curChCodeWithOffSet < (int)('A'))
            {
                int newOffSet = (int)('A') - curChCodeWithOffSet;  // positive
                messageToEncrypt[index] = (int)('Z') + 1 - newOffSet;
            }
            else if (curChCodeWithOffSet > (int)('Z'))
            {
                int newOffSet = curChCodeWithOffSet - (int)('Z');  
                messageToEncrypt[index] = (int)('A') - 1 + newOffSet;  // positive
            }
            else 
            {
                messageToEncrypt[index] = curChCodeWithOffSet;
            }
        }
        else if ((int)messageToEncrypt[index] >= (int)('a') && (int)messageToEncrypt[index] <= (int)('z'))  // lowercase letter
        {
            if (curChCodeWithOffSet < (int)('a'))
            {
                int newOffSet = (int)('a') - curChCodeWithOffSet;  // positive
                messageToEncrypt[index] = (int)('z') + 1 - newOffSet;
            }
            else if (curChCodeWithOffSet > (int)('z'))
            {
                int newOffSet = curChCodeWithOffSet - (int)('z');
                messageToEncrypt[index] = (int)('a') - 1 + newOffSet;  // positive
            }
            else
            {
                messageToEncrypt[index] = curChCodeWithOffSet;
            }
        }
    }
    
    return messageToEncrypt;
}
char* Decrypt(char* messageToDecrypt, int offSet)
{
    offSet = -offSet;
    
    return Encrypt(messageToDecrypt, offSet);
}