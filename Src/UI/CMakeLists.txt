cmake_minimum_required(VERSION 3.15.0)

set(MODULE_LISTS
    MainWidget
    VAbstractWidget
)
AddModule(MODULE_LISTS)

set(QT_COMPONENTS
    Core
    Widgets
)
LinkQtComponents(${QT_COMPONENTS})

target_include_directories(MainWidget PRIVATE VAbstractWidget)