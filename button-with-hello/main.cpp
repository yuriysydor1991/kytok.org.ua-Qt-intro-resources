#include <QApplication>
#include "HelloButtonWindow.h"

// головна функція C++ програми
int main (int argc, char** argv)
{
  // створюємо обробник подій
  QApplication eventLoop(argc, argv);

  // створюємо примірник головного вікна
  HelloButtonWindow justAWindow;

  // показуємо вікно на екран
  justAWindow.show();

  //запускаємо цикл обробки подій вікон
  return eventLoop.exec();
}
