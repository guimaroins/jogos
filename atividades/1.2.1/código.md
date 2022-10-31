~~~ruby
#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    //INICIALIZACAO 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("amongas",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);    
    

    //EXECUÇÃO 
    SDL_SetRenderDrawColor(ren, 0,0,50,0x00); //janela
    SDL_RenderClear(ren);
    
    
    /*AMONGAS*/
    //preenchimento
    SDL_SetRenderDrawColor(ren, 75, 0, 140,0x00);
    SDL_Rect p1 = {380, 114, 224, 240}; //preenchimento1
    SDL_RenderFillRect(ren, &p1);
    SDL_Rect p2 = {460, 82, 96, 320}; //preenchimento2
    SDL_RenderFillRect(ren, &p2);
    SDL_Rect p3 = {556, 82, 64, 192}; //preenchimento3
    SDL_RenderFillRect(ren, &p3);
    SDL_Rect p4 = {364, 178, 16, 160}; //preenchimento4
    SDL_RenderFillRect(ren, &p4);
    SDL_Rect p5 = {348, 210, 16, 64}; //preenchimento5
    SDL_RenderFillRect(ren, &p5);
    
    //contorno
    SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    SDL_Rect r1 = {332,194, 16,96}; //quadrado1
    SDL_RenderFillRect(ren, &r1);
    SDL_Rect r2 = {348,162, 16, 48}; //quadrado2
    SDL_RenderFillRect(ren, &r2);
    SDL_Rect r3 = {364,130, 16, 48}; //quadrado3
    SDL_RenderFillRect(ren, &r3);
    SDL_Rect r4 = {380,114, 16, 32}; //quadrado4
    SDL_RenderFillRect(ren, &r4);
    SDL_Rect r5 = {396,114, 32, 16}; //quadrado5
    SDL_RenderFillRect(ren, &r5);
    SDL_Rect r6 = {428,98, 16, 64}; //quadrado6
    SDL_RenderFillRect(ren, &r6);
    SDL_Rect r7 = {412,146, 16, 64}; //quadrado7
    SDL_RenderFillRect(ren, &r7);
    SDL_Rect r8 = {396,194, 16, 48}; //quadrado8
    SDL_RenderFillRect(ren, &r8);
    SDL_Rect r9 = {380,226, 16, 48}; //quadrado9
    SDL_RenderFillRect(ren, &r9);
    SDL_Rect r10 = {348,274, 16, 64}; //quadrado10
    SDL_RenderFillRect(ren, &r10);
    SDL_Rect r11 = {364,258, 16, 32}; //quadrado11
    SDL_RenderFillRect(ren, &r11);
    SDL_Rect r12 = {524,146, 128, 96}; //quadrado12
    SDL_RenderFillRect(ren, &r12);
    SDL_Rect r13 = {492,146, 16, 64}; //quadrado13
    SDL_RenderFillRect(ren, &r13);
    SDL_Rect r14 = {508,130, 16, 96}; //quadrado14
    SDL_RenderFillRect(ren, &r14);
    SDL_Rect r15 = {524,130, 112, 16}; //quadrado15
    SDL_RenderFillRect(ren, &r15);
    SDL_Rect r16 = {652, 162, 16, 64}; //quadrado16
    SDL_RenderFillRect(ren, &r16);
    SDL_Rect r17 = {444, 98, 32, 16}; //quadrado17
    SDL_RenderFillRect(ren, &r17);
    SDL_Rect r18 = {460, 82, 32, 16}; //quadrado18
    SDL_RenderFillRect(ren, &r18);
    SDL_Rect r19 = {476, 66, 112, 16}; //quadrado19
    SDL_RenderFillRect(ren, &r19);
    SDL_Rect r20 = {572, 82, 32, 16}; //quadrado20
    SDL_RenderFillRect(ren, &r20);
    SDL_Rect r21 = {604, 82, 16, 32}; //quadrado21
    SDL_RenderFillRect(ren, &r21);
    SDL_Rect r22 = {620, 98, 16, 32}; //quadrado22
    SDL_RenderFillRect(ren, &r22);
    SDL_Rect r23 = {620, 242, 16, 32}; //quadrado23
    SDL_RenderFillRect(ren, &r23);
    SDL_Rect r24 = {604, 258, 16, 64}; //quadrado24
    SDL_RenderFillRect(ren, &r24);
    SDL_Rect r25 = {588, 306, 16, 48}; //quadrado25
    SDL_RenderFillRect(ren, &r25);
    SDL_Rect r26 = {572, 338, 16, 32}; //quadrado26
    SDL_RenderFillRect(ren, &r26);
    SDL_Rect r27 = {556, 354, 16, 32}; //quadrado27
    SDL_RenderFillRect(ren, &r27);
    SDL_Rect r28 = {540, 370, 16, 32}; //quadrado28
    SDL_RenderFillRect(ren, &r28);
    SDL_Rect r29 = {524, 386, 16, 32}; //quadrado29
    SDL_RenderFillRect(ren, &r29);
    SDL_Rect r30 = {476, 402, 48, 16}; //quadrado30
    SDL_RenderFillRect(ren, &r30);
    SDL_Rect r31 = {460, 386, 16, 16}; //quadrado31
    SDL_RenderFillRect(ren, &r31);
    SDL_Rect r32 = {524, 322, 16, 16}; //quadrado32
    SDL_RenderFillRect(ren, &r32);
    SDL_Rect r33 = {364, 338, 16, 16}; //quadrado33
    SDL_RenderFillRect(ren, &r33);
    SDL_Rect r34 = {380, 354, 48, 16}; //quadrado34
    SDL_RenderFillRect(ren, &r34);
    SDL_Rect r35 = {428, 338, 48, 16}; //quadrado35
    SDL_RenderFillRect(ren, &r35);
    SDL_Rect r36 = {444, 322, 48, 16}; //quadrado36
    SDL_RenderFillRect(ren, &r36);
    SDL_Rect r37 = {460, 306, 64, 16}; //quadrado37
    SDL_RenderFillRect(ren, &r37);
    SDL_Rect r38 = {444, 354, 16, 32}; //quadrado38
    SDL_RenderFillRect(ren, &r38);
    
    
    //EFEITO
    SDL_SetRenderDrawColor(ren, 125, 125, 125,0x00);
    SDL_RenderDrawLine(ren, 340, 0, 340, 160); //linha vertical lateral
    SDL_RenderDrawLine(ren, 680, 0, 680, 150); //linha vertical lateral
    SDL_RenderDrawLine(ren, 452, 0, 452, 140); //linha vertical frontal
    SDL_RenderDrawLine(ren, 532, 0, 532, 226); //linha vertical frontal
    SDL_RenderDrawLine(ren, 612, 0, 612, 132); //linha vertical frontal
    SDL_RenderDrawLine(ren, 410, 0, 410, 74); //linha vertical traseira
    SDL_RenderDrawLine(ren, 580, 0, 580, 58); //linha vertical traseira
    
    
    //REFLEXO
    SDL_RenderDrawPoint(ren, 540, 146);
    SDL_RenderDrawPoint(ren, 556, 194);
    SDL_RenderDrawPoint(ren, 588, 188);
    SDL_RenderDrawPoint(ren, 572, 210);
    SDL_RenderDrawPoint(ren, 620, 159);
    SDL_RenderDrawPoint(ren, 636, 178);
    SDL_RenderDrawPoint(ren, 604, 200);
    SDL_RenderDrawPoint(ren, 616, 148);
    SDL_RenderDrawPoint(ren, 632, 186);
    SDL_RenderDrawPoint(ren, 524, 162);
    SDL_RenderDrawPoint(ren, 540, 194);
    SDL_RenderDrawPoint(ren, 556, 162);
    SDL_RenderDrawPoint(ren, 588, 188);
    SDL_RenderDrawPoint(ren, 572, 200);
    SDL_RenderDrawPoint(ren, 598, 146);
    SDL_RenderDrawPoint(ren, 636, 178);
    SDL_RenderDrawPoint(ren, 614, 170);
    SDL_RenderDrawPoint(ren, 580, 154);
    SDL_RenderDrawPoint(ren, 632, 186);
    SDL_RenderDrawPoint(ren, 624, 210);
    SDL_RenderPresent(ren);
    SDL_Delay(5000);


    //FINALIZACAO
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
~~~
