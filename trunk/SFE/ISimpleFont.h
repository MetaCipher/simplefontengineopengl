//=============================================================================
// DevThinkTank
//
// Authors:
//		Shane Farris
//=============================================================================
#ifndef __ISIMPLEFONT_H__
#define __ISIMPLEFONT_H__

#include <string>

using namespace std;

namespace DevThinkTank 
{
	interface ISimpleFont 
	{
	public:
		virtual ~ISimpleFont() { };

        bool OnInit();
		bool OnLoad(string File);
		void OnLoadFontmap(int PointSize);
		void OnRender(int PointSize, int X, int Y, string Text);
		void OnCleanup();
		void SetFontPointSize(int Point);
        void SetFontPixelSize(int Pixels);
	};
}

#endif