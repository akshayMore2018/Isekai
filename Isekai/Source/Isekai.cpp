#include "Core/Engine.h"


class Isekai : public Hunter::Engine
{
public:
    Isekai()
    {

    }

    ~Isekai()
    {

    }
};


int main()
{
    std::unique_ptr<Isekai> App = std::make_unique<Isekai>();

    if (App->Init())
    {
        App->Run();
    }

    return 0;
}

