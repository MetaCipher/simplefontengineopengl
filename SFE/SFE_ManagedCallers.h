//==============================================================================
// DevThinkTank
//
// Authors:
//		Torren
//==============================================================================
#ifndef _SFE_MANAGEDCALLS_H_
#define _SFE_MANAGEDCALLS_H_

#include "ISimpleFont.h"
#include "SFE.h"

//#ifdef __cplusplus
extern "C"  {
//#endif

	SFE_API DevThinkTank::ISimpleFont* CreateSFEObject();
	SFE_API void DisposeSFEObject(DevThinkTank::ISimpleFont* pSFEObject);
	SFE_API bool InitializeSFE(DevThinkTank::ISimpleFont* pSFEObject);
	SFE_API bool LoadFontFile(DevThinkTank::ISimpleFont* pSFEObject, std::string File);
	SFE_API void LoadFontmap(DevThinkTank::ISimpleFont* pSFEObject, int PointSize);
	SFE_API void RenderFont(DevThinkTank::ISimpleFont* pSFEObject, int PointSize, int X, int Y, std::string Text);
	SFE_API void CleanupSFEFont(DevThinkTank::ISimpleFont* pSFEObject);
	SFE_API void SetPointSize(DevThinkTank::ISimpleFont* pSFEObject, int Point);
	SFE_API void SetPixelSize(DevThinkTank::ISimpleFont* pSFEObject, int Pixels);

//#ifdef __cplusplus
}
//#endif

#endif
