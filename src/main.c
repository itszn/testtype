#include <stdio.h>
#include <ft2build.h>
#include FT_FREETYPE_H

FT_Library  library;
FT_Face     face;

int main() {
  FT_Error e;
  e = FT_Init_FreeType( &library );
  if (e) {
	  printf("Could not init FT\n");
	  return 0;
  }
  e = FT_New_Face( library,
	  "C:\\WINDOWS\\Fonts\\COMIC.TTF", 0, &face );
  if (e == FT_Err_Unknown_File_Format) {
	  printf("Could not open font bad format\n");
	  return 0;
  }
  else if (e) {
	  printf("Could not open font\n");
	  return 0;
  }
  FT_Load_Glyph(face, 0, FT_LOAD_FORCE_AUTOHINT);
  printf("Survived FT_Load_Glyph\n");
}
