//=============================================================================
// DevThinkTank
//
// Authors:
//		Tim Jones
//=============================================================================
#ifndef _DTT_SFE_H_
#define _DTT_SFE_H_

#include <windows.h>
#include <gl/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <iostream>
#include <vector>

#include "ISimpleFont.h"
#include "SFE_FontMap.h"
#include "SFE_Char.h"

//=============================================================================
namespace DevThinkTank 
{
	class SFE_API SFE : public ISimpleFont
	{
	public:
		// ---- Fields ----
		std::vector<SFE_FontMap>    FontMaps;

	protected:
		FT_Library	    Library;
		FT_Face         FontFace;
		FT_GlyphSlot    GlyphSlot;

	public:
		// ---- Constructors/Destructor ----
		SFE();
		virtual ~SFE();

		// ---- Properties ----
		virtual void SetFontPointSize(int Point);
		virtual void SetFontPixelSize(int Pixels);

		// ---- Functions ----

		// Loading Routines
		virtual bool OnInit();
		virtual bool OnLoad(std::string File);
		virtual void OnLoadFontmap(int PointSize);

		// Rendering Routines
		virtual void OnRender(int PointSize, int X, int Y, std::string Text);

		// Cleanup
		virtual void OnCleanup();

	protected:
		int NextPowerTwo(int X);
	};
};

//=============================================================================

#endif
