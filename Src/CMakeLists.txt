cmake_minimum_required(VERSION 3.15.0)

set(ADD_RESOURCE_LIST
    ${CMAKE_SOURCE_DIR}/Resource/Resource.qrc
)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    ${ADD_RESOURCE_LIST}
)

set(MODULE_LISTS
    SaveLog
    Universal
)
AddModule(MODULE_LISTS)

add_subdirectory(UI)

set(QT_COMPONENTS
    Core
    Widgets
)
LinkQtComponents(${QT_COMPONENTS})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"

    # WIN32_EXECUTABLE TRUE
)

target_include_directories(MainWidget PRIVATE Universal VAbstractWidget)
target_include_directories(VAbstractWidget PRIVATE Universal)