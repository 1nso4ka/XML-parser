#include "xmlparser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   XMLparser w;
   w.show();
   return a.exec();
}
