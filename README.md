# QtGeneralTemplate
* New Qt General project template
* CMake and QMake build
* Being perfected...
  
## Tree directory
```
+-- CMakeLists.txt
+-- compile.bat
+-- deploy.bat
+-- Profile.pri
+-- QtGeneralTemplate.pro
+-- Src\
|   +-- CMakeLists.txt
|   +-- Src.pri
|   +-- main.cpp
|   +-- MainWidget\
|   |   +-- CMakeLists.txt
|   |   +-- MainWidget.pri
|   |   +-- MainWidget.cpp
|   |   +-- MainWidget.h
|   +-- Universal\
|   |   +-- CMakeLists.txt
|   |   +-- Universal
|   |   +-- Universal.pri
|   |   +-- Universal.hpp
|   +-- thirdparty\
|   |   +-- qcustomplot\
|   |   |   +-- CMakeLists.txt
|   |   |   +-- qcustomplot.h
|   |   |   +-- qcustomplot.cpp
+-- Resource\
|   +-- Resource.qrc
|   +-- updateInfo.txt
|   +-- style\
|   |   +-- MainWidget.css
|   +-- img\
|   |   +-- background.png
|   +-- video\


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