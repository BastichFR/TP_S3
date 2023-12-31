#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Updates the display.
//
// renderer: Renderer to draw on.
// texture: Texture that contains the image.
void draw(SDL_Renderer* renderer, SDL_Texture* texture)
{
    if(SDL_RenderCopy(renderer, texture, NULL, NULL) != 0)
        errx( 1, "Failed to copy texture : %s \n", SDL_GetError());

    SDL_RenderPresent(renderer);
}

// Event loop that calls the relevant event handler.
//
// renderer: Renderer to draw on.
// texture: Texture to display.
void event_loop(SDL_Renderer* renderer, SDL_Texture* texture)
{
    SDL_Event event;

    while (1)
    {
        // Waits for an event.
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            // If the "quit" button is pushed, ends the event loop.
            case SDL_QUIT:
                return;

            // If the window is resized, updates and redraws the .
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    draw(renderer, texture);
                }
                break;
        }
    }
}

int main(int argc, char** argv)
{
    // Checks the number of arguments.
    if (argc != 2)
        errx(EXIT_FAILURE, "Usage: image-file");

    // - Initialize the SDL.
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
		errx( 1, "Failed to init SDL : %s \n", SDL_GetError());

    // - Create a window.
    SDL_Window *window = SDL_CreateWindow("display", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 0, 0, 0);
    SDL_SetWindowResizable(window, SDL_TRUE);

    // - Create a renderer.
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, 0);


    // - Create a texture from the image.
    SDL_Texture* texture = IMG_LoadTexture(renderer, argv[1]);
    if(texture == NULL)
            errx( 1, "Failed to load img : %s \n", SDL_GetError());

    // Gets the width and the height of the texture.
    int w, h;
    if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // - Resize the window according to the size of the image.
    SDL_SetWindowSize(window, w, h);

    // - Dispatch the events.
    event_loop(renderer, texture);


    // - Destroy the objects.
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}