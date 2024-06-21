#pragma once
#include "pch.hpp"

namespace gfx
{
    struct Symbol
    {
        wchar_t ch;
        WORD color;

        Symbol(wchar_t c = L'#', char col = 0);

        static char GetColorID(uint front, uint back);
    };

    template <uint h, uint v>
    using SymbolMatrix = std::array<std::array<Symbol, h>, v>;
    
    template <uint h, uint v>
    using SymbolMatrixPtr = std::unique_ptr<SymbolMatrix<h, v>>;

    template<uint h, uint v>
    class Printer
    {   
        static HANDLE h_; 

        static inline char GetColor();
        static inline void SetColor(char color);

        SymbolMatrixPtr<h, v> mat_;

        void PrintSymbol( uint x, uint y); 

        public:
        uint GetSize() const;
        std::tuple<uint, uint> ClampPosition( uint x, uint y);

        Symbol GetPoint (uint x, uint y);

        void DrawPoint(const Symbol &symbol, uint x, uint y);       
        void Fill(const Symbol &symbol);

        void Present();

        Printer();
    };
        
    void ClearScr();
}

#include "Printer.ipp"

