// MathClient.cpp : Client app for MathLibrary DLL.
 //#include "pch.h" //Uncomment for Visual Studio 2017 and earlier
#include <windows.h>
#include <iostream>
//#include "caesar.h"
using namespace std; 


char* Encrypt(char* messageToEncrypt, int offSet);
// Pointer to sum function
typedef double(*sum_ptr_t)(double, double);
// Pointer to multiply function
typedef double(*multiply_ptr_t)(double, double);
 
int main() {
 
    char message[] = "XYZ";
    cout << Encrypt(message, 1);
    
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

        }
        else if ((int)messageToEncrypt[index] >= (int)('0') && (int)messageToEncrypt[index] <= (int)('9'))
        {
        }
        
    }
    return messageToEncrypt;
}
char* Decrypt(char* messageToDecrypt, int offSet)
{
    return messageToDecrypt;
}