[![Anaconda-Server Badge](https://anaconda.org/mlamarre/pyvulkan/badges/installer/conda.svg)](https://conda.anaconda.org/mlamarre)

# Vulkan Python Bindings

## Overview

These python bindings are for the most part generated from vk.xml in [Vulkan-Docs](https://github.com/KhronosGroup/Vulkan-Docs) using a script derived from [generator.py](https://github.com/KhronosGroup/Vulkan-Docs/blob/1.0/src/spec/generator.py). 

* genswigi.py generates two SWIG interfaces files vulkan.ixx and shared_ptr.ixx;
* swig.exe generates the actual bindings from pyvulkan.i which includes these generated interface files.

Because of they are generated from the spec, the bindings are 100% complete, but not 100% tested.

Also included is pyglslang, Python binding for the glslang library that implements GLSL to SPIR-V compilation.

## How to build

The build is based on CMake but currently it only works on Windows with Python x64 (2.7 and 3.5), other variants should be relatively easy to add, but 32bit variants will be tricky to implement because Vulkan's handle types are not uniform on 32bit architecture.

Conda recipes are available in the conda-recipes subfolder but they rely on some absolute path right now for the dependencies.

### Dependencies

* Numpy
* [Vulkan-Docs](https://github.com/KhronosGroup/Vulkan-Docs)
* [SWIG](https://github.com/swig/swig)
* Lunar Vulkan SDK (tested with 1.0.13)

The Lunar Vulkan SDK glslang and spirv-tools libraries are required to build pyglslang which is required to compile GLSL to bytecode.

To build these libraries, follow the instruction in C:\VulkanSDK\<version>\Samples\README.md

**However**, on Windows, it's mandatory to add the following line to every CMakeList.txt

'''
add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)
'''

With MSVS the same value for _ITERATOR_DEBUG_LEVEL must be shared between all compilation units which includes all static libs.

pyvulkan must link with some static libraries built with _ITERATOR_DEBUG_LEVEL=0 so this forces all other static libraries to do use this value. 

### Command line

Example for a cloned repo in c:\dev\pyvulkan using Visual Studio 2015, this is for an out of source CMake build, in a empty folder c:\build\pyvulkan

```
cd c:\build\pyvulkan
cmake ..\..\dev\pyvulkan -G "Visual Studio 14 2015 Win64" -DSWIG_DIR=C:\DEV\swigwin-3.0.8 -DSWIG_EXECUTABLE=C:\dev\swigwin-3.0.8\swig.exe -DNUMPY_SWIG_DIR=C:\dev\pyvulkan\numpy_swig\ -DCMAKE_INSTALL_PREFIX=c:\build\pyvulkan  -DVULKAN_INCLUDE_DIR=C:\dev\Vulkan-Docs\src -DVULKAN_LIB_DIR=c:/VulkanSDK/1.0.13.0/Bin -DGLSLANG_INCLUDE_DIR=c:/VulkanSDK/1.0.13.0/glslang/glslang/Public;c:/VulkanSDK/1.0.13.0/glslang/glslang/Include -DGLSLANG_DIR=C:/VulkanSDK/1.0.13.0/glslang/build -DSPIRVTOOLS_DIR=C:/VulkanSDK/1.0.13.0/spirv-tools/build

```

### Conda build commands

If you forked the project to make your own conda package, edit the *bld.bat* and *meta.yaml* files under *conda-recipes* subfolders with you local path and forked github URL.

Here's an example build command:

```
cd c:\dev\pyvulkan\conda-recipes
conda build pyglslang
conda build pyvulkan
```

### Tests

Coverage is very limited. Currently we have the equivalent of the "template" sample in the Lunar SDK. It's a textured cube. 

More test cases are welcome.



