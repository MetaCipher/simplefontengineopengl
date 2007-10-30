#include "SFE.h"

#include <iostream>
#include "SDL.h"

//#pragma comment(lib, "SFE")
using namespace DevThinkTank;

SFE FontEngine;
bool Running = true;
SDL_Surface* Surf_Display = NULL;

int     FPS         = 0;
int     NumFrames   = 0;
long    OldTime     = 0;

bool OnInit() 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    16);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  16);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   16);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  16);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,    16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,  16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,   16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,  16);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL)) == NULL) {
        return false;
    }

    SDL_WM_SetCaption("Simple Font Engine", "Simple Font Engine");

    //--------------------------------------------------------------------------
    // OpenGL
    //--------------------------------------------------------------------------
    glShadeModel(GL_SMOOTH);
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 640, 480, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    FontEngine.OnInit();

	if(FontEngine.OnLoad("./fonts/verdana.ttf") == false) {
		return -1;
	}

    //Preload PointSize fonts
    FontEngine.OnLoadFontmap(16);
	FontEngine.OnLoadFontmap(32);

    //Switch to a different font
	if(FontEngine.OnLoad("./fonts/porkys.ttf") == false) {
		return -1;
	}

	//Preload PointSize fonts
	FontEngine.OnLoadFontmap(64);

    return true;
}

void OnEvent(SDL_Event* Event) 
{
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}

void OnRender() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    char Buffer[255];
    sprintf(Buffer, "Frames per Second : %d", FPS);

    //Pointsize, X, Y, String
    FontEngine.OnRender(16, 50, 50, Buffer);
    FontEngine.OnRender(32, 50, 100, Buffer);
    FontEngine.OnRender(64, 50, 200, Buffer);
    FontEngine.OnRender(8, 50, 300, Buffer); //Wasn't preloaded, SFE will load it automatically

    if(OldTime + 1000 < SDL_GetTicks()) {
        FPS = NumFrames;
        NumFrames = 0;

        OldTime = SDL_GetTicks();
    }

    NumFrames++;

    SDL_GL_SwapBuffers();
}