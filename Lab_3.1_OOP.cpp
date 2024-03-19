#include <iostream>
#include <Windows.h>
#include "Date.h"
#include "RunProgram.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    RunProgram runapp;
    runapp.getUserOption();

    return 0;
}
