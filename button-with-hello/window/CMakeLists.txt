cmake_minimum_required(VERSION 3.16.3)

# розшукуємо програму moc для
# генерації додаткового коду Qt
find_program(
        Qt5AUTOMOC_EXECUTABLE
        moc
        moc.exe
)

message(STATUS "Qt5AUTOMOC_EXECUTABLE: ${Qt5AUTOMOC_EXECUTABLE}")

# якщо програму не знайдено - виводимо фатальну помилку
if(NOT Qt5AUTOMOC_EXECUTABLE)
    message(FATAL_ERROR "No moc Qt5 executable found, please install Qt5 dev package")
endif()

# додаємо ціль для генерування додаткового коду
# за допомогою програми moc для Qt-вікна
add_custom_target(
        HelloButtonWindowMocCompilationTarget
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/HelloButtonWindow.h" -o ${CMAKE_BINARY_DIR}/HelloButtonWindow.moc.h
        BYPRODUCTS ${CMAKE_BINARY_DIR}/HelloButtonWindow.moc.h
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/HelloButtonWindow.h
        COMMENT "QT5 HelloButtonWindow header moc generation command"
)

# додаємо ціль-бібліотеку для компіляції коду вікна HelloButtonWindow
add_library(
        HelloButtonWindowCompilationTarget
        OBJECT
        HelloButtonWindow.cpp
)

# вказуємо що перед компіляцією необхідно спочатку
# згенерувати додатковий код за допомогою moc-програми
# для Qt вікна HelloButtonWindow
add_dependencies(
        HelloButtonWindowCompilationTarget
        HelloButtonWindowMocCompilationTarget
)

# обов'язкові прапорці компіляції для Qt
target_compile_options(
        HelloButtonWindowCompilationTarget
        PRIVATE -fPIC
)

# директорії розміщення файлів-підключень Qt і проекту
target_include_directories(
        HelloButtonWindowCompilationTarget
        PRIVATE ${CMAKE_BINARY_DIR} ${Qt5GeneralIncludes}
)
