cmake_minimum_required(VERSION 3.16.3)

# підключаємо необхідні пакети Qt5
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# визначаємо шляхи розміщення заголовкових файлів
get_target_property(Qt5Includes Qt5::Widgets INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(Qt5CoreIncludes Qt5::Core INTERFACE_INCLUDE_DIRECTORIES)

# встановлюємо змінну з усіма шляхами для Qt5
set(Qt5GeneralIncludes ${Qt5Includes} ${Qt5CoreIncludes})

# додаємо піддиректорію вікна у якій оголошується бібліотека
add_subdirectory(window)

# додаємо цільовий виконуваний файл для вікна демонстрації
add_executable(
        Qt5HelloButtonWindow
        main.cpp
)

# додаємо шляхи підключень файлів
target_include_directories(
        Qt5HelloButtonWindow
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/window ${Qt5GeneralIncludes}
)

# вказуємо з якими бібліотеками
# головний виконуваний файл повинен
# компонуватись
target_link_libraries(
        Qt5HelloButtonWindow
        HelloButtonWindowCompilationTarget
        Qt5::Core
        Qt5::Widgets
)

# встановлюємо деякі обов'язкові прапорці
# компілювання для Qt
target_compile_options(
        Qt5HelloButtonWindow
        PRIVATE -fPIC
)
