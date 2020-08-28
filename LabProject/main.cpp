#include "LoadFile.h"
#include "Window.h"
#include <QApplication>

//int main() {
    //LoadFile lf;
  //  Window Window(0);
//}
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadFile lf;

    Window mainWindow(&lf);
    mainWindow.show();

    return app.exec();

}