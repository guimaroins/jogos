#include <SDL2/SDL.h>
#include <assert.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("up/down: tamanho; left/right: velocidade; clique do mouse: cor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 520, 520, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    int re = 1;
    int g = 4;
    int b = 7;
    int tam = 20;
    int timer = 50;
    int mover = 1;
    SDL_Rect r = {0, 250, tam, tam};
    int espera = 50;
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
        SDL_RenderPresent(ren);

        Uint32 antes = SDL_GetTicks();
        int isevt = SDL_WaitEventTimeout(&evt, espera);
        
        if (isevt) {
            espera -= (SDL_GetTicks() - antes);
            if (espera < 0) {espera = 0;}
            
            if (evt.type == SDL_KEYDOWN) {    
		switch (evt.key.keysym.sym) {  //aumentar tamanho
                    case SDLK_UP:
                    	if (tam<48) {tam += 4;}
                    	r.w = tam;
                    	r.h = tam;
                        break;
                    case SDLK_DOWN:		//diminuir tamanho
                    	if (tam>4) {tam -= 4;}
                    	r.w = tam;
                    	r.h = tam;
                        break;
                  case SDLK_RIGHT:		//aumentar velocidade
                  	if (mover < 20) {mover += 3;};
                  	if (timer > 5) {timer -= 5;};
                       break;
                    case SDLK_LEFT:		//diminuir velocidade
                        if (mover > 1) {mover -= 3;};
                        if (timer < 100) {timer += 5;};
                        break;}}
            
            if(evt.type == SDL_MOUSEBUTTONDOWN){  //mudar de cor de acordo com a posição que clicar no fundo
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x>250) {x=-x;}
                if (y>250) {y=-y;}
                re = x;
                b = y;               
                g = x + y;}}
        
        else {
        	espera = timer;
            
	    if (r.x >= (260 - tam/2) && r.x <= 520 - tam){
        	if (r.y >= (260 - tam/2)) {r.x+=mover; r.y-=mover;}
    		if (r.y < (260 - tam/2)) {r.x-=mover; r.y-=mover;}}
            if (r.x < (260 - tam/2) && r.x >= 0) {
        	if (r.y >= (260 - tam/2)) {r.x += mover; r.y += mover;}
        	if (r.y < (260 - tam/2)){r.x -= mover; r.y += mover;}}
            if (r.x < 0) {r.x = 0; r.y = 260 - tam/2;}
            if (r.y > 520 - tam) {r.x = 260 - tam/2; r.y = 520 - tam;}
            if (r.x > 520 - tam) {r.x = 520 - tam; r.y = 260 - tam/2;}
            if (r.y < 0) {r.x = 260 - tam/2; r.y = 0;}
        	
	    SDL_RenderPresent(ren);}}

SDL_DestroyRenderer(ren); //finalização
SDL_DestroyWindow(win);
SDL_Quit();}
