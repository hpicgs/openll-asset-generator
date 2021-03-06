
#include <llassetgen/llassetgen.h>


#include <cassert>

#include <ft2build.h>  // NOLINT include order required by freetype
#include FT_FREETYPE_H


namespace llassetgen
{


FT_Library freetype;


void init()
{
    FT_Error init_error = FT_Init_FreeType(&freetype);
    (void)init_error;
    assert(init_error == 0);
}


} // namespace llassetgen
