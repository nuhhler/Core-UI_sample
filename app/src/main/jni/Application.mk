#APP_STL := stlport_static
APP_STL := gnustl_static

APP_ABI := armeabi armeabi-v7a mips x86

# generate native function:
# cd .../app/src/main
# javah -classpath java -jni -d jni com.gab.test.core_ui_sample.Core

# How to build C++ part of application
# cd .../main/jni
# ndk-build