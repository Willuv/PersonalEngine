#include "../src/Core/Engine.h"

using namespace engine;

int main() 
{
    if(!init()) 
    {
        return -1;
    }
    run();
    shutdown();
}