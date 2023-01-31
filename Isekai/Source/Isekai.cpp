#include "Core/Engine.h"

int main()
{
    std::unique_ptr<Hunter::Engine> App = std::make_unique<Hunter::Engine>();

    if (App->Init())
    {
        App->Run();
    }

    return 0;
}

