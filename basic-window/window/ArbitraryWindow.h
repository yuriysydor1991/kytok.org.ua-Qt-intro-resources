//
// Created by cc on 24.11.23.
//

#ifndef ARBITRARYWINDOW_H
#define ARBITRARYWINDOW_H

// підключаємо оголошення класу QMainWindow
#include <QMainWindow>

/*
 * Створюємо клас довільного вікна ArbitraryWindow
 * для відображення на екрані.
*/
class ArbitraryWindow:
  // обов'язково потрібно вказати клас QMainWindow
  // у якості батьківського класу
  public QMainWindow
{
    // обов'язковий виклик макросу!
    Q_OBJECT

public:
  ArbitraryWindow();

private slots:

private:
};

#endif //ARBITRARYWINDOW_H
