#include <Game.hpp>

Game *g_game = 0;

int main(int argc, char *args[]){

    std::cout << "Initializing game\n";

    IMG_Init(IMG_INIT_PNG);
    
    if(TheGame::Instance()->init("Capitulo 1", 100, 100, 640, 480, false)){
        while(TheGame::Instance()->running()){
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);
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
