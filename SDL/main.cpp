#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    int x, y;
    SDL_Event event;
    while (true){
        SDL_GetMouseState(&x, &y);
        SDL_PollEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                cerr << "Down at (" << x << ' ' << y << " )\n";
                break;
            case SDL_MOUSEBUTTONUP:
                cerr << "Up at (" << x << ' ' << y << " )\n";
                break;
        }
        SDL_Delay(100);
    }

    SDL_Texture* background = graphics.loadTexture("bikiniBottom.jpg");
    graphics.prepareScene(background);

    graphics.presentScene();
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = graphics.loadTexture("Spongebob.png");
    graphics.renderTexture(spongeBob, 200, 200);

	graphics.presentScene();
	waitUntilKeyPressed();

	SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    graphics.quit();
    return 0;
}