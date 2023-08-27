# QtGeneralTemplate
* New Qt General project template
* CMake and QMake build
* Being perfected...
  
## Tree directory
```
+-- CMakeLists.txt
+-- compile.bat
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
+-- Resource\
|   +-- Resource.qrc
|   +-- updateInfo.txt
|   +-- style\
|   |   +-- MainWidget.css
|   +-- img\
|   |   +-- background.png
|   +-- video\


```

## Used(Windows)

* Build with QMake
```bash
$ ./compile.bat
$ ./build/xxx.exe
```

* Build with CMake
```shell
$ mkdir build
$ cd build
$ cmake .. && cmake --build . --target all
$ ./build/bin/xxx.exe
```