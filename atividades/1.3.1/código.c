#include <SDL2/SDL.h>
#include <math.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("dvd",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         520, 520, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    int re = 1;
    int g = 4;
    int b = 7;
    /* EXECUÇÃO */
    
    SDL_Rect r = { 0, 250, 20, 20};
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, re, g, b,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);
        SDL_Delay(10);
        if (r.x >= 250){
        	if (r.y >= 250) {
    			r.x+=1;
    			r.y-=1;
    		}
    		if (r.y < 250) {
    			r.x-=1;
    			r.y-=1;
    		}
	}
        if (r.x <250) {
        	if (r.y >= 250){
			r.x += 1;
        		r.y += 1;
        	}
        	if (r.y < 250){
			r.x -= 1;
        		r.y += 1;
        	}
        }
	re += 3;
	b += 1;
	g += 2;
	if (re == 25) {
		re = g - 5;
	}
	if (b == 255) {
		b = 0 + g;
	}
	if (g == 255) {
		g = 5;
	}
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
