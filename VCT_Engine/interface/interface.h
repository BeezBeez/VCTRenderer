#pragma once
#include "..\render_window.h"

class Interface
{
    public:
        Interface();
        virtual ~Interface();

        void Initialize(const RenderWindow &activeWindow);
        void Terminate();
        void Render();

        // Application specific UI code
        void Draw();
};

