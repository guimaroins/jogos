#include <SDL2/SDL.h>

int main (int argc, char* args[]) {

    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 100, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */ 
    int count = 0;
    int cores[10][3];
    int re = 70;
    int g = 20;
    int b = 48;
    SDL_Rect r = { 40,20, 10,10 };
    SDL_Rect q[10];
    SDL_Event evt;
    
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
	int i = 0; 
		
	for (i;i<count;i++) {SDL_SetRenderDrawColor(ren, cores[i][0],cores[i][1],cores[i][2],0x00); SDL_RenderFillRect(ren,&q[i]);}
	SDL_RenderPresent(ren);
	
	SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    r.y -= 5;
                    break;
                case SDLK_DOWN:
                    r.y += 5;
                    break;
                case SDLK_LEFT:
                    r.x -= 5;
                    break;
                case SDLK_RIGHT:
                    r.x += 5;
                    break; } }
                    
        if (evt.type == SDL_MOUSEBUTTONDOWN) {
        	switch (evt.button.button){
        		case SDL_BUTTON_LEFT:
        			if (count < 10) {	    
        				SDL_Rect temp = {evt.button.x, evt.button.y, 10, 10};
					q[count] = temp;
					cores[count][0] = re;
					cores[count][1] = g;
					cores[count][2] = b;
        				count += 1;
        			} break; } }
        
        if (evt.type == SDL_QUIT) {break;}
			         
   	re += 78;
	b += 50;
	g += 32;
	if (re >= 255) {re = g - 30;}
	if (b >= 255) {b = 85;}
	if (g >= 255) {g = 47;}
    }
    
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit(); }
