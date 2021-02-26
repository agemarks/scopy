# Scopy Gui Library

## Overview
This library contains all the widgets that are used in Scopy

## Library structure
All the classes are contained in the namespace
```cpp
namespace scopy {
        namespace gui {
                ...
        }
}
```

## Directory Structure

| Directory | Description |
| --------- | ----------- |
| include | Public header files of the library |
| src | Source files of the library |
| ui | Ui files of the library |
| resources | Resources files of the library |

## Consuming this library using CMake
TODO
```cmake
find_package(Scopy COMPONENTS gui REQUIRED)
target_link_libraries(yourtarget [INTERFACE|PUBLIC|PRIVATE] scopy::gui)
```
