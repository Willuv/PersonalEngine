#include "Engine.h"
#include "../Platform/Window.h"

using namespace Platform;

namespace engine {
    bool init() {
        return createWindow("My Game", 800, 600);
    }

    void run() {
        runWindowLoop();
    }

    void shutdown() {
        destroyWindow();
    }
}