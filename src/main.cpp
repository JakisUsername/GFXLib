#include "pch.hpp"
#include "gfx.hpp"

using namespace std;

int main()
{
    auto s = gfx::Symbol(GFX_CHAR_HMID, gfx::Symbol::GetColorID(12, 0)); 
    auto s2 = gfx::Symbol(GFX_CHAR_HIGH, gfx::Symbol::GetColorID(15, 0));

    auto d = gfx::Printer<20, 20>();

    d.Fill(s);
    gfx::Form::DrawRect(d ,s2 ,0 ,0 ,20 ,20 ,false);

    d.Present();
    system("pause >nul");

    return 0;
}
