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
        WindowWithMenuMocCompilationTarget
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/WindowWithMenu.h" -o ${CMAKE_BINARY_DIR}/WindowWithMenu.moc.h
        BYPRODUCTS ${CMAKE_BINARY_DIR}/WindowWithMenu.moc.h
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/WindowWithMenu.h
        COMMENT "QT5 WindowWithMenu header moc generation command"
)

# додаємо ціль-бібліотеку для компіляції коду вікна ArbitraryWindow
add_library(
        WindowWithMenuCompilationTarget
        OBJECT
        WindowWithMenu.cpp
)

# вказуємо що перед компіляцією необхідно спочатку
# згенерувати додатковий код за допомогою moc-програми
# для Qt вікна ArbitraryWindow
add_dependencies(
        WindowWithMenuCompilationTarget
        WindowWithMenuMocCompilationTarget
)

# обов'язкові прапорці компіляції для Qt
target_compile_options(
        WindowWithMenuCompilationTarget
        PRIVATE -fPIC
)

# директорії розміщення файлів-підключень Qt і проекту
target_include_directories(
        WindowWithMenuCompilationTarget
        PRIVATE ${CMAKE_BINARY_DIR} ${Qt5GeneralIncludes}
)
