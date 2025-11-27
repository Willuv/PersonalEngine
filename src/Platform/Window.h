#pragma once

namespace Platform {
    bool createWindow(const char* title, int width, int height);
    void runWindowLoop();
    void destroyWindow();
}