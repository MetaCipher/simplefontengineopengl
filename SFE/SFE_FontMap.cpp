//==============================================================================
#include "SFE_FontMap.h"

//==============================================================================
DevThinkTank::SFE_FontMap::SFE_FontMap() {
    PointSize = 0;
}

//==============================================================================
void DevThinkTank::SFE_FontMap::OnRender(int Char, int X, int Y) {
    if(Char <= 0 || Char >= 255) return;

    int OffsetX = CharList[Char].OffsetX;
    int OffsetY = -CharList[Char].OffsetY;

    glBindTexture(GL_TEXTURE_2D, CharList[Char].Texture);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(X + OffsetX,                             Y + CharList[Char].Height + OffsetY, 0);
        glTexCoord2f(0, 0); glVertex3f(X + OffsetX,                             Y + OffsetY, 0);
        glTexCoord2f(1, 0); glVertex3f(X + CharList[Char].Width + OffsetX,      Y + OffsetY, 0);
        glTexCoord2f(1, 1); glVertex3f(X + CharList[Char].Width + OffsetX,      Y + CharList[Char].Height + OffsetY, 0);
    glEnd();
}

//------------------------------------------------------------------------------
void DevThinkTank::SFE_FontMap::OnCleanup() {
    for(int i = 0;i < 255;i++) {
        glDeleteTextures(1, &CharList[i].Texture);

        CharList[i].Texture = 0;
    }
}

//==============================================================================
DevThinkTank::SFE_Char* DevThinkTank::SFE_FontMap::GetChar(int Char) {
    if(Char <= 0 || Char >= 255) return NULL;

    return &CharList[Char];
}

//==============================================================================
