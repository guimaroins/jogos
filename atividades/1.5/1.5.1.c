#include <SDL2/SDL.h>
#include <assert.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("三", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 520, 520, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    int re = 1;
    int g = 4;
    int b = 7;
    SDL_Rect r = {0, 250, 20, 20};
    SDL_Rect r1 = {250, 250, 15, 15 };
    SDL_Rect r2 = {520, 520, 15, 15 };
    int espera = 500;
    SDL_Event evt;
    Uint32 antes = SDL_GetTicks();
    int isevt = SDL_WaitEventTimeout(&evt, espera);    

    while (1) {
    
        SDL_PollEvent(&evt); //fecha a janela
        if(evt.type == SDL_QUIT) {break;}
    
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, re, g, b, 0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_SetRenderDrawColor(ren, 220, 0, 0, 0x00);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 150, 0, 150, 0x00);
        SDL_RenderFillRect(ren, &r2);
        SDL_RenderPresent(ren);

        Uint32 antes = SDL_GetTicks();
        int isevt = SDL_WaitEventTimeout(&evt, espera);
        
        if (isevt) {
            espera -= (SDL_GetTicks() - antes);
            if (espera < 0) {espera = 0;}
            
            if (evt.type == SDL_KEYDOWN) {    //retângulo teclado
		switch (evt.key.keysym.sym) {
                    case SDLK_UP:
                        r1.y -= 5;
                        break;
                    case SDLK_DOWN:
                        r1.y += 5;
                        break;
                    case SDLK_LEFT:
                        r1.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        r1.x += 5;
                        break;}}
            
            if(evt.type == SDL_MOUSEMOTION){  //retângulo grudado no mouse
                int x, y;
                SDL_GetMouseState(&x, &y);
                r2.x = x;
                r2.y = y;}}
        
        else {		  //retângulo ciclo
            espera = 10;
	    if (r.x >= 250){
        	if (r.y >= 250) {r.x+=1; r.y-=1;}
    		if (r.y < 250) {r.x-=1; r.y-=1;}}
            if (r.x <250) {
        	if (r.y >= 250) {r.x += 1; r.y += 1;}
        	if (r.y < 250){r.x -= 1; r.y += 1;}}
        	
	    if (r.x<0) {r.x = 0;}
	    if (r.x>500) {r.x=500;}
    	    if (r.y<0) {r.y=0;}
	    if (r.y>500) {r.y=500;}
	    
	    re += 3;
	    b += 1;
	    g += 2;
    	    if (re >= 255) {re = g - 5;}
	    if (b >= 255) {b = g;}
	    if (g >= 255) {g = 5;}
	    SDL_RenderPresent(ren);}}

SDL_DestroyRenderer(ren); //finalização
SDL_DestroyWindow(win);
SDL_Quit();}
