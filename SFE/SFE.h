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
	class SFE : ISimpleFont
	{
	    public:
            std::vector<SFE_FontMap>    FontMaps;

		private:
			FT_Library	    Library;

			FT_Face         FontFace;

			FT_GlyphSlot    GlyphSlot;

		//Constructors
		public:
			SFE();
			~SFE();

		//Loading Routines
		public:
            bool OnInit();

			bool OnLoad(std::string File);

			void OnLoadFontmap(int PointSize);

		//Rendering Routines
		public:
			void OnRender(int PointSize, int X, int Y, std::string Text);

		//Cleanup
		public:
			void OnCleanup();

        public:
            void SetFontPointSize(int Point);

            void SetFontPixelSize(int Pixels);

        private:
            int NextPowerTwo(int X);
	};
};

//=============================================================================

#endif
