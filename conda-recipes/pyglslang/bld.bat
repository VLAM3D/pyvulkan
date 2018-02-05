mkdir build
cd build

if "%PY_VER%"=="2.7" (
   set MSVC_VER=14.0
   set VS_VERSION="14.0"
   set VS_MAJOR="14"
   set VS_YEAR="2015"   
)
set CMAKE_GENERATOR="Visual Studio 14 2015 Win64"
set CMAKE_FLAGS=-DCMAKE_INSTALL_PREFIX=%PREFIX%
set CMAKE_FLAGS=%CMAKE_FLAGS% -DSWIG_DIR=C:\DEV\swigwin-3.0.12
set CMAKE_FLAGS=%CMAKE_FLAGS% -DSWIG_EXECUTABLE=C:\dev\swigwin-3.0.12\swig.exe
set CMAKE_FLAGS=%CMAKE_FLAGS% -DNUMPY_SWIG_DIR=C:\dev\pyvulkan\numpy_swig\
set CMAKE_FLAGS=%CMAKE_FLAGS% -DCMAKE_BUILD_TYPE=Release
set CMAKE_FLAGS=%CMAKE_FLAGS% -DVULKAN_SDK=c:/VulkanSDK/1.0.65.0

cmake -G %CMAKE_GENERATOR% %CMAKE_FLAGS% ..

set CMAKE_CONFIG="Release"
cmake --build . --config %CMAKE_CONFIG% --target _pyglslang

xcopy "Release\_pyglslang.pyd" "%SP_DIR%"
xcopy "pyglslang.py" "%SP_DIR%"

if errorlevel 1 exit 1

:: Add more build steps here, if they are necessary.

:: See
:: http://docs.continuum.io/conda/build.html
:: for a list of environment variables that are set during the build process.
