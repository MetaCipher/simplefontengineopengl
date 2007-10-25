//=============================================================================
// DevThinkTank
//
// Authors:
//		Tim Jones
//=============================================================================
#ifndef _DTT_SFE_FONTMAP_H_
    #define _DTT_SFE_FONTMAP_H_

#include <windows.h>
#include <gl/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <iostream>

#include "SFE_Char.h"

//==============================================================================
namespace DevThinkTank {
    class SFE_FontMap {
        public:
            SFE_Char    CharList[255];

            int         PointSize;

        public:
            SFE_FontMap();

        public:
            void OnRender(int Char, int X, int Y);

            void OnCleanup();

        public:
            DevThinkTank::SFE_Char* GetChar(int Char);
    };
};

//=============================================================================
#endif
