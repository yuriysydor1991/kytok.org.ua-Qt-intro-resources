cmake_minimum_required(VERSION 3.16.3)

# обов'язкова команда для встановлення
# параметрів поточного проекту.
project(
        QtIntroProject
        HOMEPAGE_URL "http://www.kytok.org.ua/post/qt-lehkyj-start"
        DESCRIPTION "A simple demo project for Qt intro article"
        LANGUAGES CXX
)

#Базовий приклад використання QApplication
# і QMainWindow-похідного класу для відображення
# пустого головного вікна
add_subdirectory(basic-window)
