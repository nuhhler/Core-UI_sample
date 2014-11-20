LOCAL_PATH := $(call my-dir)

ARCH := $(APP_ABI)

include $(CLEAR_VARS)

# имя модуля, который будет вызываться в Java при помощи System.loadLibrary()
LOCAL_MODULE    := core

LOCAL_C_INCLUDES += /home/sdv/work/android-ndk-r10/sources/cxx-stl/gnu-libstdc++/4.9/include/

LOCAL_SRC_FILES := com_gab_test_core_ui_sample_Core.cpp AndroidGabCoreWrapper.cpp GabCore.cpp GabAsyncResponse.cpp GabContact.cpp AndroidGui.cpp

LOCAL_CPPFLAGS := -std=c++11 -pthread -fexceptions --rtti

LOCAL_STATIC_LIBRARIES := cpufeatures

LOCAL_LDLIBS :=  -llog

#STLPORT_FORCE_REBUILD := true

include $(BUILD_SHARED_LIBRARY)

$(call import-module, android/cpufeatures)