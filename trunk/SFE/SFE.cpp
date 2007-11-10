//==============================================================================
#include "SFE.h"

//==============================================================================
DevThinkTank::SFE::SFE() {
}

//------------------------------------------------------------------------------
DevThinkTank::SFE::~SFE() {
}

//==============================================================================
bool DevThinkTank::SFE::OnInit() {
	if(FT_Init_FreeType(&Library)) {
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------
bool DevThinkTank::SFE::OnLoad(std::string File) {
	int Return = FT_New_Face(Library, File.c_str(), 0, &FontFace);

	if(Return == FT_Err_Unknown_File_Format) {
		std::cerr << "SFE::OnLoad > " << Return << " : Unknown file format : " << File << "\n";
		return false;
	}else
		if(Return) {
			std::cerr << "SFE::OnLoad > " << Return << " : Unable to load font file : " << File << "\n";
			return false;
		}

		GlyphSlot = FontFace->glyph;

		return true;
}

//------------------------------------------------------------------------------
void DevThinkTank::SFE::OnLoadFontmap(int PointSize) {
	DevThinkTank::SFE::SetFontPointSize(PointSize);

	SFE_FontMap newFontMap;

	newFontMap.PointSize = PointSize;

	for(int c = 0;c < 255;c++) {
		glGenTextures(1, &newFontMap.CharList[c].Texture);

		FT_Load_Char(FontFace, (char)c, FT_LOAD_RENDER);

		newFontMap.CharList[c].CharWidth   = GlyphSlot->bitmap.width;
		newFontMap.CharList[c].CharHeight  = GlyphSlot->bitmap.rows;

		newFontMap.CharList[c].Width   = NextPowerTwo(GlyphSlot->bitmap.width);
		newFontMap.CharList[c].Height  = NextPowerTwo(GlyphSlot->bitmap.rows);
		newFontMap.CharList[c].AdvanceX = GlyphSlot->advance.x >> 6;

		newFontMap.CharList[c].OffsetX = GlyphSlot->bitmap_left;
		newFontMap.CharList[c].OffsetY = GlyphSlot->bitmap_top;

		GLubyte* Data = new GLubyte[2 * newFontMap.CharList[c].Width * newFontMap.CharList[c].Height];

		for(int j = 0;j < newFontMap.CharList[c].Height; j++) {
			for(int i = 0;i < newFontMap.CharList[c].Width; i++){
				Data[2 * (i + j * newFontMap.CharList[c].Width)] = Data[2 * (i + j* newFontMap.CharList[c].Width) + 1] =
					(i >= GlyphSlot->bitmap.width || j >= GlyphSlot->bitmap.rows) ?
					0 : GlyphSlot->bitmap.buffer[i + GlyphSlot->bitmap.width * j];
			}
		}

		glBindTexture(GL_TEXTURE_2D, newFontMap.CharList[c].Texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, newFontMap.CharList[c].Width, newFontMap.CharList[c].Height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, Data);

		delete [] Data;
	}

	FontMaps.push_back(newFontMap);
}

//==============================================================================
void DevThinkTank::SFE::OnRender(int PointSize, int X, int Y, std::string Text) {
	int Index = -1;

	for(int i = 0;i < FontMaps.size();i++) {
		if(FontMaps[i].PointSize == PointSize) {
			Index = i;
			break;
		}
	}

	if(Index < 0 || Index >= FontMaps.size()) {
		DevThinkTank::SFE::OnLoadFontmap(PointSize);
		Index = FontMaps.size() - 1;

		if(Index <= 0) {
			return;
		}
	}

	for(int i = 0;i < Text.size();i++) {
		FontMaps[Index].OnRender(Text[i], X, Y);

		SFE_Char* tempChar = FontMaps[Index].GetChar(Text[i]);

		if(tempChar) {
			X += tempChar->AdvanceX;
		}
	}
}

//==============================================================================
void DevThinkTank::SFE::OnCleanup() {
	for(int i = 0;i < FontMaps.size();i++) {
		FontMaps[i].OnCleanup();
	}

	FontMaps.clear();

	FT_Done_FreeType(Library);
}

//==============================================================================
void DevThinkTank::SFE::SetFontPointSize(int Point) {
	FT_Set_Char_Size(FontFace, 0, Point * 64, 72, 72);
}

//------------------------------------------------------------------------------
void DevThinkTank::SFE::SetFontPixelSize(int Pixels) {
	FT_Set_Pixel_Sizes(FontFace, 0, Pixels);
}

//==============================================================================
int DevThinkTank::SFE::NextPowerTwo(int X) {
	int rval = 1;

	while(rval < X) rval <<= 1;

	return rval;
}

