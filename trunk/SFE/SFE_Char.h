//=============================================================================
// DevThinkTank
//
// Authors:
//		Tim Jones
//=============================================================================
#ifndef _DTT_SFE_CHAR_H_
    #define _DTT_SFE_CHAR_H_

#include <windows.h>
#include <gl/gl.h>

//=============================================================================
namespace DevThinkTank {
    class SFE_Char {
        public:
            SFE_Char();

        public:
            GLuint          Texture;

            int             CharWidth;
            int             CharHeight;

            int             Width;
            int             Height;

            int             AdvanceX;

            int             OffsetX;
            int             OffsetY;
    };
};

//=============================================================================
#endif
