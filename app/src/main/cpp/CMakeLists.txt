# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("mp3lametest")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.设置生成so库的名字
        mp3lame

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
#        native-lib.cpp
        mp3lame/bitstream.c
        mp3lame/encoder.c
        mp3lame/gain_analysis.c
        mp3lame/id3tag.c
        mp3lame/fft.c
        mp3lame/lame.c
        mp3lame/mpglib_interface.c
        mp3lame/newmdct.c
        mp3lame/presets.c
        mp3lame/psymodel.c
        mp3lame/quantize.c
        mp3lame/quantize_pvt.c
        mp3lame/reservoir.c
        mp3lame/set_get.c
        mp3lame/tables.c
        mp3lame/takehiro.c
        mp3lame/util.c
        mp3lame/vbrquantize.c
        mp3lame/VbrTag.c
        mp3lame/version.c
        mp3-lame.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        mp3lame

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
