#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <assert.h>
    
int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("三", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 520, 520, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	
    /* EXECUÇÃO */
    
    start:

    SDL_Rect r = {0, 200, 20, 20};
    SDL_Rect r1 = {0, 170, 15, 15};
    SDL_Rect r2 = {0, 230, 15, 15};
    SDL_Rect chegada = {480, 0, 25, 520};
    int espera = 500;
    SDL_Event evt;
    Uint32 antes = SDL_GetTicks();
    int isevt = SDL_WaitEventTimeout(&evt, espera);    
    int x, y;
    char*primeiro[] = {"vencedor: vermelho", "vencedor: preto", "vencedor: roxo"};
    int vencedor = 3;
    char reiniciar[9] = {"REINICAR"};
    int click;

    while (1) {
    
        SDL_PollEvent(&evt); //fecha a janela
        if(evt.type == SDL_QUIT) {break;}
    
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_SetRenderDrawColor(ren, 220, 0, 0, 0x00);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 150, 0, 150, 0x00);
        SDL_RenderFillRect(ren, &r2);
        SDL_SetRenderDrawColor(ren, 100, 100, 100, 0x00);
        SDL_RenderFillRect(ren, &chegada);
        if (r.x == 460 && r1.x == 465 && r2.x == 465) {
        	stringRGBA(ren, 130, 80, primeiro[vencedor], 200,0,0,255);
   		SDL_Rect botao = {130, 100, 100, 35};
       	SDL_SetRenderDrawColor(ren, 150, 150, 255, 255);
        	SDL_RenderFillRect(ren, &botao);
        	click = stringRGBA(ren, 145, 115, reiniciar, 0, 0, 200, 255);}
        
        SDL_RenderPresent(ren);
        
        	
        Uint32 antes = SDL_GetTicks();
        int isevt = SDL_WaitEventTimeout(&evt, espera);
        
        if (isevt) {				  //"delay"
            espera -= (SDL_GetTicks() - antes);
            if (espera < 0) {espera = 0;}
            
            switch (evt.type) {
            
		case SDL_KEYDOWN:  //retângulo teclado
		switch (evt.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (r1.x > 0) r1.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        if (r1.x < 465) r1.x += 5;
                        if (r1.x == 465 && r.x < 460 && r2.x < 465) {
                        	vencedor = 0;}
                        break;}
            
           	case SDL_MOUSEMOTION:  //retângulo grudado no mouse
		SDL_GetMouseState(&x, &y);
               	if (x < (r2.x + 10)) {
               		if (r2.x < 465) r2.x = x;
               		if (r2.x > 465) r2.x = 465;}
               	if (r2.x == 465 && r.x < 460 && r1.x < 465) vencedor = 2;         
               	               	
		case SDL_MOUSEBUTTONDOWN: //botao reiniciar
        	switch (evt.button.button){
        		case SDL_BUTTON_LEFT:
        			if (x <= 165 && x >= 130 && y >= 100 && y <= 200) goto start;
        }}}

        else {		  //retângulo ciclo
            espera = 10;
	    if (r.x < 460) r.x += 1;
	    SDL_RenderPresent(ren);
	    if (r.x == 460 && r1.x < 465 && r2.x < 465) vencedor = 1;}}

SDL_DestroyRenderer(ren); //finalização
SDL_DestroyWindow(win);
SDL_Quit();}
