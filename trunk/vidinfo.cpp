#include "SDL.h"
#include <iostream>

const SDL_VideoInfo* g_pVideoInfo = NULL;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
//	SDL_SetVideoMode(800,600,24, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
	g_pVideoInfo = SDL_GetVideoInfo();

	char szVidDriver[256];
	SDL_VideoDriverName(szVidDriver, 255);

	// output information about the current video display
	std::cout <<"Video Information" << std::endl;
	std::cout <<"Hardware Surfaces Possible: " << g_pVideoInfo->hw_available << std::endl;
	std::cout <<"Window Manage Available: " << g_pVideoInfo->wm_available << std::endl;
	std::cout <<"Are blits from hw to hw accelerated?: " << g_pVideoInfo->blit_hw << std::endl;
	std::cout <<"Are blits from hw to hw /w color keys accelerated?: " << g_pVideoInfo->blit_hw_CC << std::endl;
	std::cout <<"Are blits from hw to hw /w alpha accelerated?: " << g_pVideoInfo->blit_hw_A << std::endl;
	std::cout <<"Are blits from sw to hw accelerated?: " << g_pVideoInfo->blit_sw << std::endl;
	std::cout <<"Are blits from sw to hw /w color keys accelerated?: " << g_pVideoInfo->blit_sw_CC << std::endl;
	std::cout <<"Are blits from sw to hw /w alpha accelerated?: " << g_pVideoInfo->blit_sw_A << std::endl;
	std::cout <<"Are color fills accelerated?: " << g_pVideoInfo->blit_fill << std::endl;
	std::cout <<"Total video card memory: " << g_pVideoInfo->video_mem << std::endl;
	std::cout <<"Bits per pixel: " << g_pVideoInfo->vfmt->BitsPerPixel << std::endl;
	std::cout <<"Video Driver: " << szVidDriver << std::endl;
	SDL_Quit();
	return 0;
}
