#include "pch.hpp"
#include "Printer.hpp"

gfx::Symbol::Symbol(wchar_t c, char col) {
    ch = c;
    color = col;
}

char gfx::Symbol::GetColorID(uint front, uint back) {
    if (front > 15) front = 15;
    if (back > 7) back = 7;

    back *= 16;
    
    int id = front + back;
    if (id > 128) id = 128;

    return (char)id;
}

void gfx::ClearScr() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
