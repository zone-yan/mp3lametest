//
// Created by yz on 2023/2/14.
//
#include <jni.h>

//#include <string>

//#include "android/log.h"

#include "mp3lame/lame.h"

//#include "net_iaround_utils_Mp3Lame.h"可以在这个头文件里定义一些变量和方法，但是感觉没啥必要，因为逻辑比较简单，一个类就行

//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , "mp3-lame", __VA_ARGS__)

extern "C" {
lame_t lame;
int numChannel;
JNIEXPORT void JNICALL
Java_net_iaround_utils_Mp3Lame_initEncoder(JNIEnv *env, jclass clazz, jint num_channels,
                                           jint sample_rate, jint bit_rate, jint mode,
                                           jint quality) {
    lame = lame_init();
    numChannel = num_channels;
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
    int buffer;
    //num_samples这个参数是每个通道的采样点数量，根据实例化AudioRecord的参数audioFormat以及初始化的声道数量来决定的
    //例如当AudioFormat为16bit的时候，单通道输入, 一个采样点大小为2byte, 则nsamples = input有效数据长度(byte) / 2，即len_input/2
    //AudioFormat为16bit，双通道输入的时候 input有效数据长度(byte) / 2(16bite为2byte) / 2(通道数为2)，即即len_input/2/2 = len_input/4
    if (numChannel > 1){
        buffer = lame_encode_buffer_interleaved(lame,pcm,len_input/4,result, len_output);
    } else {
        buffer = lame_encode_buffer(lame,pcm,NULL,len_input/2,result, len_output);
    }
//    LOGD("encode");
    (*env).ReleaseByteArrayElements(input, (jbyte *) pcm, 0);
    (*env).ReleaseByteArrayElements(output, (jbyte *) result, 0);
    return buffer;
}

}