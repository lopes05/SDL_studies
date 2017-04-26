#include <Game.hpp>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *args[]){
    Uint32 frameStart, frameTime;
    std::cout << "Initializing game\n";

    IMG_Init(IMG_INIT_PNG);
    
    if(TheGame::Instance()->init("Capitulo 1", 100, 100, 640, 480, false)){
        while(TheGame::Instance()->running()){
            frameStart =  SDL_GetTicks();
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            frameTime = SDL_GetTicks() - frameStart;

            if(frameTime < DELAY_TIME){
                SDL_Delay((int) DELAY_TIME - frameTime);
            }
        }
    
        
    }
    else{
        std::cout << "Fail to init game -- " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "Game closing\n"; 
    TheGame::Instance()->clean();

    return 0;
}
