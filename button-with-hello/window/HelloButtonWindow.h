//
// Created by cc on 25.11.23.
//

#ifndef HELLOBUTTONWINDOW_H
#define HELLOBUTTONWINDOW_H

// підключаємо оголошення класу QMainWindow
// і інші необхідні класи
#include <QMainWindow>
#include <QRadioButton>
#include <QLineEdit>

/*
 * Створюємо клас довільного вікна ArbitraryWindow
 * для відображення на екрані.
*/
class HelloButtonWindow:
  // обов'язково потрібно вказати клас QMainWindow
  // у якості батьківського класу
  public QMainWindow
{
    // обов'язковий виклик макросу!
    Q_OBJECT

public:
  HelloButtonWindow();

private slots:

  void interact();

private:

  QRadioButton* hello;
  QLineEdit* edit;
};

#endif //HELLOBUTTONWINDOW_H
