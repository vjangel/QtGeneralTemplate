# QtGeneralTemplate
* New Qt General project template
* CMake and QMake build
* Being perfected...
  
## Tree directory
```
QtGeneralTemplate
├─ cmakes\
│  ├─ buildDefaults.cmake
│  └─ LinkQtComponents.cmake
├─ dependent\
│  └─ font
│     └─ myfont.ttf
├─ Resource\
│  ├─ img\
│  │  └─ background.png
│  ├─ style\
│  │  └─ MainWidget.css
│  ├─ Resource.qrc
│  └─ updateInfo.txt
├─ Src\
│  ├─ SaveLog\
│  │  ├─ CMakeLists.txt
│  │  ├─ SaveLog.cpp
│  │  ├─ SaveLog.h
│  │  └─ SaveLog.pri
│  ├─ thirdparty\
│  │  └─ qcustomplot\
│  │     ├─ CMakelists.txt
│  │     ├─ qcustomplot.cpp
│  │     └─ qcustomplot.h
│  ├─ UI\
│  │  ├─ MainWidget\
│  │  │  ├─ CMakeLists.txt
│  │  │  ├─ MainWidget.cpp
│  │  │  ├─ MainWidget.h
│  │  │  └─ MainWidget.pri
│  │  ├─ VAbstractWidget\
│  │  │  ├─ Resources\
│  │  │  │  ├─ git\
│  │  │  │  ├─ img\
│  │  │  │  │  └─ background.png
│  │  │  │  ├─ media\
│  │  │  │  ├─ style\
│  │  │  │  │  └─ VAbstractWidget.css
│  │  │  │  └─ VAbstractWidget.qrc
│  │  │  ├─ CMakeLists.txt
│  │  │  ├─ VAbstractWidget
│  │  │  ├─ VAbstractWidget.cpp
│  │  │  ├─ VAbstractWidget.h
│  │  │  └─ VAbstractWidget.pri
│  │  ├─ CMakeLists.txt
│  │  └─ UI.pri
│  ├─ Universal\
│  │  ├─ CMakeLists.txt
│  │  ├─ Universal
│  │  ├─ Universal.hpp
│  │  └─ Universal.pri
│  ├─ CMakeLists.txt
│  ├─ main.cpp
│  └─ Src.pri
├─ CMakeLists.txt
├─ compile.bat
├─ deploy.bat
├─ LICENSE
├─ Profile.pri
├─ QtGeneralTemplate.pro
└─ README.md


```

## Usage(Windows)

* Build with QMake
```bash
$ ./compile.bat
$ ./build/release/QtGeneralTemplate.exe
```

* Build with CMake
```bash
$ mkdir build
$ cd build
$ cmake .. && cmake --build . --target all
$ ./build/bin/QtGeneralTemplate.exe
```