#include <iostream>
#include "Game.h"


int main()
{
    //Initializing a Game Object
    Game game;

    //Application(Game) Loop
    while (game.isRunning())
    {
        //Update
        game.Update();
        //Rendering
        game.Render();
    }

    return 0;
}
