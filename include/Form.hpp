#include "pch.hpp"
#include "Printer.hpp"

namespace gfx {
    class Form
    {
        Form() {}
        
    public:
        template <uint h, uint v>
        static void DrawRect(Printer<h, v> &buffer, const Symbol &symbol, uint x, uint y, uint x2, uint y2, bool fill = true) {
            auto p = buffer.ClampPosition(x, y);
            auto p2 = buffer.ClampPosition(x2, y2);
            
            x = std::get<0>(p);
            y = std::get<1>(p);

            x2 = std::get<0>(p2); 
            y2 = std::get<1>(p2);

            for (uint i = x; i <= x2; i++) {
                for (uint j = y; j <= y2; j++) {
                    if (!fill) { 
                        bool isEdgeX = i == x || i == x2;
                        bool isEdgeY = j == y || j == y2;

                        if (isEdgeX || isEdgeY) buffer.DrawPoint(symbol, i, j);
                    }
                    else buffer.DrawPoint(symbol, i, j);
                }
            }
        }
    };
}
