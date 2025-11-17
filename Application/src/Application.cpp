/////////////////////////////////////////////////////////////////
//	Author: Caio Jose Borba Vilar Guimaraes
//	Description: main application executable that runs all game structures
//	License: GPL 3.0
//	Filename: Application.cpp
/////////////////////////////////////////////////////////////////

#include "Application.hpp"
int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        spdlog::info("Arguments: ");
        for (int i = 0; i < argc; i++)
        {
            spdlog::info("{}", argv[i]);
        }
    }
    std::unique_ptr<Engine> engine = std::make_unique<Engine>();
    engine->Run();
    // engine is automatically deleted when unique_ptr goes out of scope
    spdlog::info("Application finished");
    spdlog::info("Exiting application");

    return 0;
}