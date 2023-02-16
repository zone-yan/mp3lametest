#include <jni.h>
#include <string>
//这个是一个建立项目自动生成的，编译自己需要的so时可以用这个也可以自己新建一个.cpp文件
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mp3lametest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
