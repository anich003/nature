#include "graphics.h"

Graphics* Graphics::Instance = NULL;

Graphics* Graphics::GetInstance()
{
    if(Instance == NULL)
    {
        Instance = new Graphics();
    }
    return Instance;
}

SDL_Renderer* Graphics::GetRenderer()
{
    return Renderer;
}

bool Graphics::Init(int width, int height)
{
    Width = width;
    Height = height;
    SDL_Init(SDL_INIT_VIDEO);

    Window = SDL_CreateWindow("Nature", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    // TODO Check for failure
    IsInitialized = true;
    return IsInitialized;
}

void Graphics::Clear()
{
    SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(Renderer);
}

void Graphics::Flip()
{
    SDL_RenderPresent(Renderer);
}

Graphics::Graphics()
{
    IsInitialized = false;
    Width = 0;
    Height = 0;
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
