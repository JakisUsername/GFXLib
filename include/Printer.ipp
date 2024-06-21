#pragma once

template <uint h, uint v>
uint gfx::Printer<h, v>::GetSize() const {
    return mat_->size();
}

template <uint h, uint v>
void gfx::Printer<h, v>::PrintSymbol( uint x, uint y) {
    char currentColor = GetColor();
    auto pos = ClampPosition(x, y);
    x = std::get<0>(pos);
    y = std::get<1>(pos);

    SetColor((*mat_)[x][y].color);
    WriteConsoleW(h_, &(*mat_)[x][y].ch, 1, nullptr, nullptr);
    SetColor(currentColor);
}

template <uint h, uint v>
void gfx::Printer<h, v>::DrawPoint(const Symbol &symbol, uint x, uint y) {
    auto pos = ClampPosition(x, y);
    x = std::get<0>(pos);
    y = std::get<1>(pos);

    (*mat_)[x][y].ch = symbol.ch;
    (*mat_)[x][y].color = symbol.color;
}

template <uint h, uint v>
void gfx::Printer<h, v>::Fill(const Symbol &symbol) {
    for (uint y = 0; y < h; y++) {
        for (uint x = 0; x < h; x++) {
            DrawPoint(symbol, x, y);
        }
    }
}

template <uint h, uint v>
gfx::Printer<h, v>::Printer() {
    mat_ = std::make_unique<SymbolMatrix<h, v>>();
    Fill(Symbol());
}

template <uint h, uint v>
char gfx::Printer<h, v>::GetColor(){
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h_, &info);
    return info.wAttributes;
}

template <uint h, uint v>
std::tuple<uint, uint> gfx::Printer<h, v>::ClampPosition( uint x, uint y) {
    uint hindex = h - 1;
    uint vindex = v - 1;

    if (x > hindex) x = hindex;
    if (y > vindex) y = vindex;

    return {x, y};
}

template <uint h, uint v>
HANDLE gfx::Printer<h, v>::h_ = GetStdHandle(STD_OUTPUT_HANDLE);

template <uint h, uint v>
gfx::Symbol gfx::Printer<h, v>::GetPoint (uint x, uint y) {
    auto pos = ClampPosition(x, y);
    x = std::get<0>(pos);
    y = std::get<1>(pos);
    
    return (*mat_)[x][y];  
}

template <uint h, uint v>
void gfx::Printer<h, v>::Present () {
    ClearScr();
    for (uint y = 0; y < v; y++) {
        for (uint x = 0; x < h; x++) {
            PrintSymbol(x, y);
        }
        std::cout << '\n';
    }
}

template <uint h, uint v>
void gfx::Printer<h, v>::SetColor(char color) { 
    SetConsoleTextAttribute(h_, color);
}
