//
// Created by cc on 24.11.23.
//

// підключаємо згенерований moc-програмою
// заголовковий файл
#include "WindowWithMenu.moc.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

WindowWithMenu::WindowWithMenu()
{
  // створюємо меню "Програма" на панелі меню
  auto fileMenu = menuBar()->addMenu(tr("Програма"));

  // свтрюємо елемент субменю "Сказати привіт"
  auto hello = fileMenu->addAction(tr("Сказати привіт"));

  // поєднюємо меню з конкретним методом-слотом
  // класу sayHello
  connect(hello, SIGNAL(triggered()), this, SLOT(sayHello()));
}

void WindowWithMenu :: sayHello()
{
  // код, який показує віконечко з привітом ;)
  QMessageBox::information(
    this,
    tr("Привіт"),
    tr("Привіт, Планета!")
  );
}