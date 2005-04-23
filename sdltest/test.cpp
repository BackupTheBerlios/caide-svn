// this is an example program to test SDL functions and usage
// use extensive comments.
// created by: Stephen "RShadow" Bunn
//

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

// function prototypes
void PrintKeyInfo(SDL_KeyboardEvent*);

int main(int argc, char* argv[])
{
	std::cout <<"Number of arguments " << argc << std::endl;
	int j = 0;
	for (j=0; j <  argc; j++)
		std::cout <<"Argument: " << argv[j] << std::endl;

	// Init SDL
	std::cout <<"Initilizing SDL Video System ...";
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << std::endl <<"SDL Error: " << SDL_GetError() <<"\n";
		return -1;
	}
	std::cout <<" done" << std::endl;

	// Get available fullscreen/hardware modes
	std::cout <<"Probing video modes..." << std::endl;
	SDL_Rect **modes;
	int i;
	modes = SDL_ListModes(NULL, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(modes == (SDL_Rect **)0) {
		std::cout <<"No modes available!" << std::endl;
		return -1;
	}
	// Check if our resolution is restricted
	if(modes == (SDL_Rect **)-1) {
		std::cout <<"All resolutions available" << std::endl;
	}
	else {
		std::cout <<"Available Modes" << std::endl;
		for(i = 0; modes[i]; ++i)
			std::cout << modes[i]->w << "x" << modes[i]->h << std::endl;
	}


	std::cout <<"Using Mode: " << modes[0]->w << "x" << modes[0]->h << std::endl;
	// this might create some problems for the framebuffer if the modes are not returned 
	// from lowest to greatest.  Need to develop a fix to either take a resolution from
	// the command line or to sort the returned values from  SDL_GetVideoModes.  Under X
	// the results appear to return in the correct order; however a permanant solution
	// needs to be developed.
	

	// Create a Screen
	SDL_Surface *screen = NULL;

	screen = SDL_SetVideoMode(modes[0]->w, modes[0]->h,24,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	if (screen == NULL) {
		std::cout <<"Video Error: " << SDL_GetError() <<"\n";
		return -1;
	}

	// Blit Image to screen
	SDL_Surface *image;
	image = IMG_Load("test.jpg");
	SDL_BlitSurface(image,0 , screen, 0);
	SDL_Flip(screen);
	if (image == NULL)
		std::cout <<"Error loading image: " << IMG_GetError();

	// Load our tinytux image so we can move it around with the keys
	SDL_Rect src, dest;
	SDL_Surface *tinytux;
	tinytux = IMG_Load("tinytux.png");
	if (image == NULL) {
		std::cout <<"Error loading image: " << IMG_GetError(); 
		return -1;
	}
	SDL_BlitSurface(tinytux,0,screen,0);
	SDL_Flip(screen);
	Uint32 tuxxv = 0;
	Uint32 tuxyv = 0;
	bool bTuxUpdate = false;
	src.w = tinytux->w;
	src.h = tinytux->h;
	src.x = 0;
	src.y = 0;
	dest = src;


	SDL_Event eventMain; // Main Event variable
	int quit = 0; // loop controler
	
	// Setup Unicode translation
	SDL_EnableUNICODE(1);
	
	
	while(!quit) {
		// Poll for events
		while( SDL_PollEvent(&eventMain) ) {
			switch( eventMain.type ) {
				// Keyboard Event: Process
				case SDL_KEYUP:
					switch(eventMain.key.keysym.sym) {
						case SDLK_LEFT:
						case SDLK_RIGHT:
							tuxxv = 0;
							bTuxUpdate = true;
							std::cout <<"Stopping tux's velocity" << std::endl;
							break;
						case SDLK_UP:
						case SDLK_DOWN:
							tuxyv = 0;
							bTuxUpdate = true;
							break;
					}
					break;
					
				case SDL_KEYDOWN:
					PrintKeyInfo( &eventMain.key );
					if ( eventMain.key.keysym.sym == SDLK_q )
						quit = 1;
					switch(eventMain.key.keysym.sym) {
						case SDLK_RIGHT:
							tuxxv = 1;
							bTuxUpdate = true;
							break;
						case SDLK_LEFT:
							tuxxv = -1;
							bTuxUpdate = true;
							break;
						case SDLK_DOWN:
							tuxyv = 1;
							bTuxUpdate = true;
							break;
						case SDLK_UP:
							tuxyv = -1;
							bTuxUpdate = true;
							break;
							
					}
					break;
				// SDL Quit Event (window close)
				case SDL_QUIT:
					quit = 1;
					break;
				default:
					//`std::cout <<"Unknown Event" << std::endl;
					break;
			}
		}
		if (bTuxUpdate) {
			SDL_BlitSurface(image,0,screen,0); // Effectivly erase the background and redraw it.
			// Update the tux's coord. based upon the velocity factor
			dest.x += tuxxv;
			dest.y += tuxyv;
			SDL_BlitSurface(tinytux,&src,screen,&dest); // Now draw tux over the new background
			SDL_Flip(screen); // Everything is drawn on the screen surface so flip it into the video buffer
		}
		
	}
        std::cout <<"Leaving..." << std::endl;
	SDL_Quit();
	return 0;
}

void PrintKeyInfo( SDL_KeyboardEvent *key ){
	// Is it a release or a press
	if (key->type == SDL_KEYUP )
		std::cout <<"Release:- ";
	else
		std::cout <<"Press:- ";

	// Print the hardware scancode first
	std::cout <<"Scancode " << (int)key->keysym.scancode;

	// Print out the unicode value (if possible)
	if (key->type == SDL_KEYDOWN) {
		std::cout <<" Unicode: ";
		if ( key->keysym.unicode < 0x80 && key->keysym.unicode > 0 ) {
			std::cout << (char)key->keysym.unicode;
		}
		else {
			std::cout <<" Unicode is higher than 0x80 (" << (double)key->keysym.unicode <<")";
		}
	}

	// flush output stream
	std::cout << std::endl;
}
