//
// Created by yz on 2023/2/14.
//
#include <jni.h>

//#include <string>

//#include "android/log.h"

#include "mp3lame/lame.h"

//#include "net_iaround_utils_Mp3Lame.h"

//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , "mp3-lame", __VA_ARGS__)

extern "C" {
lame_t lame;
JNIEXPORT void JNICALL
Java_net_iaround_utils_Mp3Lame_initEncoder(JNIEnv *env, jclass clazz, jint num_channels,
                                           jint sample_rate, jint bit_rate, jint mode,
                                           jint quality) {
    lame = lame_init();
    lame_set_num_channels(lame, num_channels);
    lame_set_in_samplerate(lame, sample_rate);
    lame_set_brate(lame, bit_rate);
    lame_set_mode(lame, MPEG_mode_e(mode));
    lame_set_quality(lame,quality);
    lame_init_params(lame);

//    LOGD("init");
}

JNIEXPORT void JNICALL
Java_net_iaround_utils_Mp3Lame_destroyEncoder(JNIEnv *env, jclass clazz) {
//    LOGD("destroy");
    lame_close(lame);
    lame = NULL;
}

JNIEXPORT jint JNICALL
Java_net_iaround_utils_Mp3Lame_encodeBuffer(JNIEnv *env, jclass clazz, jbyteArray input,
                                            jint len_input, jbyteArray output, jint len_output) {
    short* pcm = (short *)(*env).GetByteArrayElements(input,NULL);
    unsigned char *result = (unsigned char *) (*env).GetByteArrayElements(output, NULL);
    int buffer = lame_encode_buffer(lame,pcm,NULL,len_input/2,result, len_output);
//    LOGD("encode");
    (*env).ReleaseByteArrayElements(input, (jbyte *) pcm, 0);
    (*env).ReleaseByteArrayElements(output, (jbyte *) result, 0);
    return buffer;
}

}