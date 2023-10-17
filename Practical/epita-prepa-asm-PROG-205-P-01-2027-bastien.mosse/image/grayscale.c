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
// colored: Texture that contains the colored image.
// grayscale: Texture that contains the grayscale image.
void event_loop(SDL_Renderer* renderer, SDL_Texture* colored, SDL_Texture* grayscale)
{
    SDL_Event event;
    SDL_Texture* t = colored;

    while (1)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                return;

            // If the window is resized, updates and redraws the .
            case SDL_WINDOWEVENT:
                // update
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    draw(renderer, t);
                }
                break;

            case SDL_KEYDOWN:

                // switch t
                if (t == colored){
                    t = grayscale;
                } else {
                    t = colored;
                }

                // update
                draw(renderer, t);

                break;
        }
    }
}

// Loads an image in a surface.
// The format of the surface is SDL_PIXELFORMAT_RGB888.
//
// path: Path of the image.
SDL_Surface* load_image(const char* path)
{
    // load surface
    SDL_Surface *surface = IMG_Load(path);
	if (surface == NULL) {
		fprintf(stderr, "Couldn't load %s: %s\n", path, SDL_GetError());
		return NULL;
	}

    // update surface to rgb
    surface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGB888, 0);

	return surface;
}

// Converts a colored pixel into grayscale.
//
// pixel_color: Color of the pixel to convert in the RGB format.
// format: Format of the pixel used by the surface.
Uint32 pixel_to_grayscale(Uint32 pixel_color, SDL_PixelFormat* format)
{
    Uint8 r, g, b;
    SDL_GetRGB(pixel_color, format, &r, &g, &b);

    double average = 0.3*r + 0.59*g + 0.11*b;
    r = g = b = average;

    Uint32 color = SDL_MapRGB(format, r, g, b);
    return color;
}

void surface_to_grayscale(SDL_Surface* surface)
{
    // get data
    Uint32* pixels = surface->pixels;
    int len = surface->w * surface->h;
    SDL_PixelFormat* format = surface->format;
    
    // lock surface
    SDL_LockSurface(surface);

    // update surface's colors
    for(int i = 0; i < len; i++){
        pixels[i] = pixel_to_grayscale(pixels[i], format);
    }

    // unlock surface
    SDL_UnlockSurface(surface);
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

    // - Create a surface from the colored image.
    SDL_Surface *surface = load_image(argv[1]);

    // - Resize the window according to the size of the image.
    SDL_SetWindowSize(window, surface->w, surface->h);

    // - Create a texture from the colored surface.
    SDL_Texture *colored = SDL_CreateTextureFromSurface(renderer, surface);

    // - Convert the surface into grayscale.
    surface_to_grayscale(surface);

    // - Create a new texture from the grayscale surface.
    SDL_Texture *grayscale = SDL_CreateTextureFromSurface(renderer, surface);

    // - Free the surface.
    SDL_FreeSurface(surface);

    // - Dispatch the events.
    event_loop(renderer, colored, grayscale);

    // - Destroy the objects.
    SDL_DestroyTexture(colored);
    SDL_DestroyTexture(grayscale);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}