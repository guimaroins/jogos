#include <SDL2/SDL.h>
#include <assert.h>

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
    Uint32 before = SDL_GetTicks();
    if (SDL_WaitEventTimeout(evt, *ms)) {
    	int temp = *ms - (SDL_GetTicks() - before);
	if (temp < 0) *ms = 0;
	else *ms = temp;
	return 1;
    } else return 0;
}

int main (int argc, char* args[]){

    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("三", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 520, 520, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = {0, 250, 20, 20};
    SDL_Rect r1 = {250, 250, 15, 15 };
    SDL_Rect r2 = {520, 520, 15, 15 };
    int espera = 10; 

    while (1) {
        
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 87, 135, 72, 0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_SetRenderDrawColor(ren, 220, 0, 0, 0x00);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 150, 0, 150, 0x00);
        SDL_RenderFillRect(ren, &r2);
        SDL_RenderPresent(ren);

	SDL_Event evt;
        int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
        
        if (isevt) {
        
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
                r2.y = y;}
                
            if(evt.type == SDL_QUIT) {break;}}
            
        else {		  //retângulo ciclo
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
	    espera = 10;}}

SDL_DestroyRenderer(ren); //finalização
SDL_DestroyWindow(win);
SDL_Quit();}
