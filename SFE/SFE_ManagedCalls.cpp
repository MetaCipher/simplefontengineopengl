//==============================================================================
// DevThinkTank
//
// Authors:
//		Torren
//==============================================================================
#include "SFE_ManagedCallers.h"

DevThinkTank::ISimpleFont* CreateSFEObject()
{
	return new DevThinkTank::SFE();
}

void DisposeSFEObject(DevThinkTank::ISimpleFont* pSFEObject)
{
	if(pSFEObject != 0)
	{
		delete pSFEObject;
		pSFEObject = 0;
	}
}

bool InitializeSFE(DevThinkTank::ISimpleFont* pSFEObject)
{
	if(pSFEObject != 0)
	{
		return pSFEObject->OnInit();
	}
}

bool LoadFontFile(DevThinkTank::ISimpleFont* pSFEObject, std::string File)
{
	if(pSFEObject != 0)
	{
		return pSFEObject->OnLoad(File);
	}
}

void LoadFontmap(DevThinkTank::ISimpleFont* pSFEObject, int PointSize)
{
	if(pSFEObject != 0)
	{
		pSFEObject->OnLoadFontmap(PointSize);
	}
}

void RenderFont(DevThinkTank::ISimpleFont* pSFEObject, int PointSize, int X, int Y, std::string Text)
{
	if(pSFEObject != 0)
	{
		pSFEObject->OnRender(PointSize, X, Y, Text);
	}
}

void CleanupSFEFont(DevThinkTank::ISimpleFont* pSFEObject)
{
	if(pSFEObject != 0)
	{
		pSFEObject->OnCleanup();
	}
}

void SetPointSize(DevThinkTank::ISimpleFont* pSFEObject, int Point)
{
	if(pSFEObject != 0)
	{
		pSFEObject->SetFontPointSize(Point);
	}
}

void SetPixelSize(DevThinkTank::ISimpleFont* pSFEObject, int Pixels)
{
	if(pSFEObject != 0)
	{
		pSFEObject->SetFontPixelSize(Pixels);
	}
}
