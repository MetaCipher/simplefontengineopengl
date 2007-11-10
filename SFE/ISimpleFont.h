//=============================================================================
// DevThinkTank
//
// Authors:
//		Shane Farris
//		Torren
//=============================================================================
#ifndef __ISIMPLEFONT_H__
#define __ISIMPLEFONT_H__

#include <string>

#ifdef DEVTHINKTANK_SFE_DLL_EXPORT
	#define SFE_API __declspec(dllexport)
#else
	#define SFE_API __declspec(dllimport)
#endif

namespace DevThinkTank 
{
	class ISimpleFont
	{
	public:
		virtual ~ISimpleFont() { };
		virtual bool OnInit() = 0;
		virtual bool OnLoad(std::string File) = 0;
		virtual void OnLoadFontmap(int PointSize) = 0;
		virtual void OnRender(int PointSize, int X, int Y, std::string Text) = 0;
		virtual void OnCleanup() = 0;
		virtual void SetFontPointSize(int Point) = 0;
        virtual void SetFontPixelSize(int Pixels) = 0;
	};
}


#endif
