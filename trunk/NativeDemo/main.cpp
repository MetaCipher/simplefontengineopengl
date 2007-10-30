#include "Helper.hpp"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:Demo")
int Demo() 
{
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnRender();
    }

    FontEngine.OnCleanup();
    SDL_Quit();

	return 1;
}

