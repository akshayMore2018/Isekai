#include "Core/Engine.h"


int main()
{
    std::unique_ptr<Engine> engine = std::make_unique<Engine>();
    if (engine->Init())
    {
        engine->Run();
    }

    return 0;
}

