#include "nature_object.h"
#include <iostream>

NatureObject::NatureObject()
{
    TheGraphics = Graphics::GetInstance();
    Renderer = Graphics::GetInstance()->GetRenderer();
}

NatureObject::~NatureObject()
{
}

void NatureObject::DrawPixel(int x, int y)
{
    SDL_RenderDrawPoint(Renderer, x, y);
}

/* 
 * Taken directly from:
 * http://members.chello.at/easyfilter/bresenham.html
 */
void NatureObject::DrawCircle(int xm, int ym, int r)
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
    do {
        DrawPixel(xm-x, ym+y); /*   I. Quadrant */
        DrawPixel(xm-y, ym-x); /*  II. Quadrant */
        DrawPixel(xm+x, ym-y); /* III. Quadrant */
        DrawPixel(xm+y, ym+x); /*  IV. Quadrant */
        r = err;
        if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
        if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
    } while (x < 0);
}

void NatureObject::DrawCircle(const Vec2 &vec, float radius)
{
    DrawCircle(vec.x, vec.y, radius);
}

void NatureObject::DrawLine(const Vec2 &tail, const Vec2& head)
{
    SDL_RenderDrawLine(Renderer, tail.x, tail.y, head.x, head.y);
}

