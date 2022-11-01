~~~ruby
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main (int argc, char* args[])
{
    //INICIALIZACAO 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("oh no",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);    
    

    //EXECUÇÃO 
    SDL_SetRenderDrawColor(ren, 0,0,10,0x00); //janela
    SDL_RenderClear(ren);
    
    
    //rosto
    int choro_poca = filledEllipseRGBA(ren, 300, 410, 100, 20, 140, 140, 200, 180);
    int cabess = filledCircleColor(ren, 300, 280, 130, 0xFF00FFFF);
    int olho_esquerdo = thickLineRGBA(ren, 215, 260, 270, 260, 10, 20,20,20,255);
    int olho_direito = thickLineRGBA(ren, 330, 260, 385, 260, 10, 20,20,20,255);
    int choro1 = thickLineRGBA(ren, 243, 263, 243, 410, 25, 140, 140, 200, 150); 
    int choro2 = thickLineRGBA(ren, 358, 263, 358, 410, 25, 140, 140, 200, 150);
    int boca = filledCircleRGBA(ren, 300, 345, 15, 0,0,0,255);
    
    //acessórios
    int chapeu_corpo = roundedBoxRGBA(ren, 200,80, 400, 200, 10, 218,165,32,0xFF); //chapéu
    int chapeu_pe = filledEllipseRGBA(ren, 300, 200, 160, 15, 218,165,32,0xFF);
    int chapeu_faixa = boxRGBA(ren, 200, 160, 400, 193, 255,0,255,0xFF);
    Sint16 vx[] = {450,445,425}; Sint16 vy[] = {240,260,255}; //confete
    int confete1 = filledPolygonRGBA(ren, vx,vy, 3, 0, 200, 200,255);
    Sint16 vx2[] = {400,420,420}; Sint16 vy2[] = {280,270,290};
    int confete2 = filledPolygonRGBA(ren, vx2,vy2, 3, 0,0,200,255);
    int confete3 = filledCircleColor(ren, 440, 280, 8, 0xFF0000FF);
    char s[50] = {"quando tem aula no dia do seu aniversario:"};
    int assoprar1 = roundedBoxRGBA(ren, 295, 340, 420, 350, 10, 100, 100, 200, 255);
    int assoprar2 = roundedBoxRGBA(ren, 360, 340, 420, 350, 10, 140, 140, 200, 255);
    int assoprar3 = filledCircleRGBA(ren, 416, 336, 17, 100,100,200,255);
    int assoprar4 = filledCircleRGBA(ren, 415, 340, 15, 140,140,200,255);
    int assoprar5 = filledCircleRGBA(ren, 415, 340, 10, 50,50,150,255);
    int frase = stringRGBA(ren, 130, 30, s, 200,0,0,255); //legenda

    SDL_RenderPresent(ren);
    SDL_Delay(5000);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
~~~
