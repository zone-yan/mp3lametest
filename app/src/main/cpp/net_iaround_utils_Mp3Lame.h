/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net_iaround_utils_Mp3Lame */

/*=====其实没什么卵用，不用这个头文件也可以，
 * 生成头文件的方法 切到包含native方法类的目录 执行javac -h . .\Mp3Lame.java就会生成对应的class文件和.h头文件
 * 之前的低版本版本是执行javah -jni com.iaround.utils.Mp3Lame=============*/

#ifndef _Included_net_iaround_utils_Mp3Lame
#define _Included_net_iaround_utils_Mp3Lame
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     net_iaround_utils_Mp3Lame
 * Method:    initEncoder
 * Signature: (IIIII)V
 */
JNIEXPORT void JNICALL Java_net_iaround_utils_Mp3Lame_initEncoder
  (JNIEnv *, jclass, jint, jint, jint, jint, jint);

/*
 * Class:     net_iaround_utils_Mp3Lame
 * Method:    destroyEncoder
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_iaround_utils_Mp3Lame_destroyEncoder
  (JNIEnv *, jclass);

/*
 * Class:     net_iaround_utils_Mp3Lame
 * Method:    encodeBuffer
 * Signature: ([BI[BI)I
 */
JNIEXPORT jint JNICALL Java_net_iaround_utils_Mp3Lame_encodeBuffer
  (JNIEnv *, jclass, jbyteArray, jint, jbyteArray, jint);

#ifdef __cplusplus
}
#endif
#endif
