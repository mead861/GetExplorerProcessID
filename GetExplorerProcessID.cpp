#include <iostream>
#include <windows.h>
#include <conio.h>
#define money_address 0x0
using namespace std;

void StartCheats() {

    int memvalue = 0;


    HWND hwnd = FindWindowA(NULL, "Explorer"); // specifies the window to act upon
        // error message if the window isn't found
    if (hwnd == NULL) {
        cout << "Explorer.exe not found!\n";
        system("PAUSE");
    }
    else {
        DWORD processID;
        // stores the process id of the window
        GetWindowThreadProcessId(hwnd, &processID);
        // gets the process id of the window
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        // opens the process with full access
        if (!handle) {
            cout << "couldnt initiate a handle on the process!\n";
            system("PAUSE");
        }

        // error message if the process ID isn't found
        if (processID == NULL) {
            cout << "cannot find Exeplorer.exe!\n";
            system("PAUSE");
        }
        else {

            //code here
            bool f = true;
            while (f)
            {
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    //Enter code for when a button is pushed here
                    f = false;
                }
                else {
                    // WriteProcessMemory(handle, (LPVOID)money_address, PlayerMoney, sizeof(Money), NULL);

                    ReadProcessMemory(handle, (LPVOID)0x0004000, &memvalue, 4, 0);
                    std::cout << "Windows Explorer Process ID: " << processID << "\n";
                    Sleep(2);
                    //Code to run until the button is pushed



                }
            }

        }

    }
}
//return 0;



int main()
{
    int choice;
    do
    {
        std::cout << "0. Quit" << std::endl << "1. Read Windows Explorer.exe Porcess ID\n";
        std::cin >> choice;


        switch (choice)
        {
        case 0:
            break;
        case 1:
            StartCheats();

        }
    } while (choice != 0);
}