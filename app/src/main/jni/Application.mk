NDK_TOOLCHAIN_VERSION := 4.9

APP_USE_CPP0X := true

APP_STL := gnustl_static

APP_CPPFLAGS := -std=c++11
APP_CPPFLAGS += -pthread
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += --rtti

APP_ABI := armeabi armeabi-v7a mips x86

# generate native function:
# cd .../app/src/main
# javah -classpath java -jni -d jni com.gab.test.core_ui_sample.Core
# javah -classpath java -jni -d jni com.gab.test.core_ui_sample.PressMe

# How to build C++ part of application
# cd .../main/jni
# ndk-build