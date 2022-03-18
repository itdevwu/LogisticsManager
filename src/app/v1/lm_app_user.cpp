#include "../lm_app.hpp"

int main(int argc, char **argv)
{
#ifdef _WIN32
    // Set the console to UTF-8
    SetConsoleOutputCP(65001);
#endif

    return 0;
}