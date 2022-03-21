#include "../lm_app.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
#ifdef _WIN32
    // Set the console encoding to UTF-8
    SetConsoleOutputCP(65001);
#endif
    QApplication a(argc, argv);
    User w;
    w.show();
    return a.exec();
}
