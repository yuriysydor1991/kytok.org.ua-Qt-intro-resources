//
// Created by cc on 24.11.23.
//

#ifndef WINDOWWITHMENU_H
#define WINDOWWITHMENU_H

// підключаємо оголошення класу QMainWindow
#include <QMainWindow>

/*
 * Створюємо клас вікна з меню WindowWithMenu
 * для відображення на екрані.
*/
class WindowWithMenu:
  // обов'язково потрібно вказати клас QMainWindow
  // у якості батьківського класу
  public QMainWindow
{
    // обов'язковий виклик макросу!
    Q_OBJECT

public:
  // конструктор у якому створюється меню
  WindowWithMenu();

private slots:

  // метод-слот для меню "Сказати привіт"
  void sayHello();

private:
};

#endif //WINDOWWITHMENU_H
