cmake_minimum_required(VERSION 3.16)

project(fultima-gen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        src/tests/Test.cpp
        src/tests/Test.h
        src/models/Accessory.h src/models/Armor.h src/models/Item.h src/models/Weapon.h
        src/models/Accessory.cpp src/models/Armor.cpp src/models/Item.cpp src/models/Weapon.cpp
        src/models/Player.cpp
        src/models/Player.h
        src/models/AttributeEnum.h
        src/core/CampaignManager.cpp
        src/core/CampaignManager.h
        src/systems/GeneratorStrategy.h
        src/systems/WeaponGenerator.cpp
        src/systems/WeaponGenerator.h
        src/systems/ArmorGenerator.cpp
        src/systems/ArmorGenerator.h
        src/systems/AccessoryGenerator.cpp
        src/systems/AccessoryGenerator.h
        src/io/JsonReader.cpp
        src/io/JsonReader.h
        src/models/Quality.h
        src/systems/QualityGenerator.cpp
        src/systems/QualityGenerator.h
        src/systems/ItemGeneratorSystem.cpp
        src/systems/ItemGeneratorSystem.h
        src/controllers/AppController.cpp
        src/controllers/AppController.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(fultima-gen
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET fultima-gen APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(fultima-gen SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(fultima-gen
            ${PROJECT_SOURCES}
            data/basic/Basic_Armor_Shield.json data/basic/Basic_Weapon_Qualities.json data/basic/Basic_Weapons.json src/core/CampaignManager.cpp src/core/CampaignManager.h src/io/JsonReader.cpp src/io/JsonReader.h src/models/Accessory.cpp src/models/Accessory.h src/models/Armor.cpp src/models/Armor.h src/models/AttributeEnum.h src/models/Item.cpp src/models/Item.h src/models/Player.cpp src/models/Player.h src/models/Quality.h src/models/Weapon.cpp src/models/Weapon.h src/systems/AccessoryGenerator.cpp src/systems/AccessoryGenerator.h src/systems/ArmorGenerator.cpp src/systems/ArmorGenerator.h src/systems/GeneratorStrategy.h src/systems/ItemGeneratorSystem.cpp src/systems/ItemGeneratorSystem.h src/systems/QualityGenerator.cpp src/systems/QualityGenerator.h src/systems/WeaponGenerator.cpp src/systems/WeaponGenerator.h src/tests/Test.cpp src/tests/Test.h
            editplayerdialogue.h editplayerdialogue.cpp editplayerdialogue.ui
            addplayerdialogue.h addplayerdialogue.cpp addplayerdialogue.ui
        )
    endif()
endif()

#target_include_directories(fultima-gen PRIVATE src)

target_link_libraries(fultima-gen PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.fultima-gen)
endif()
set_target_properties(fultima-gen PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS fultima-gen
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(fultima-gen)
endif()

message(STATUS "-------------------------------------------------")
message(STATUS "  **Project Configuration Summary**")
message(STATUS "-------------------------------------------------")
message(STATUS "  C++ ver      : ${CMAKE_CXX_STANDARD}")
message(STATUS "  C++ Compiler : ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Qt Version   : ${Qt6_VERSION}")
message(STATUS "  CMake Ver    : ${CMAKE_VERSION}")
message(STATUS "-------------------------------------------------")
