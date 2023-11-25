//
// Created by cc on 25.11.23.
//

// підключаємо згенерований moc-програмою
// заголовковий файл
#include "HelloButtonWindow.moc.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>
#include <QRadioButton>
#include <QMessageBox>

HelloButtonWindow::HelloButtonWindow():
  hello{nullptr}, edit{nullptr}
{
  // будуємо вікно взаємодії
  auto frame = new QFrame ;

  setCentralWidget(frame);

  auto button = new QPushButton(tr("Взаємодія"));
  edit = new QLineEdit;
  auto form = new QHBoxLayout;
  auto bye = new QRadioButton(tr("попрощатись"));
  hello = new QRadioButton(tr("привітатись"));

  frame->setLayout(form);

  form->addWidget(edit);
  form->addWidget(button);
  form->addWidget(bye);
  form->addWidget(hello);

  connect(button, SIGNAL(clicked()), this, SLOT(interact()));

  hello->setChecked(true);

  setWindowTitle(tr("Вікно взаємодії"));
}

void HelloButtonWindow::interact()
{
  //обчислюємо префікс взаємодії
  auto interactionText = hello->isChecked()
    ? tr("Привіт")
    : tr("До побачення") ;

  //отримуємо введений текст
  auto text = edit->displayText();

  interactionText += ", " + text + "!";

  if (text.isEmpty()) {
    // якщо відсутній текст - показати попередження
    QMessageBox::warning(
      this,
      tr("Помилка"),
      tr("Введіть ім'я!")
    );

    return ;
  }

  // код, який показує віконечко з взаємодією ;)
  QMessageBox::information(
    this,
    tr("Взаємодія"),
    interactionText
  );
}
