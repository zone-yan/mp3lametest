package net.iaround.utils;

/**
 * 这个类是需要在新建的mp3-lame.cpp中生成我们需要调用方法
 * 这个类的方法，需要在使用so库的项目中保持一致，包括包名
 */
public class Mp3Lame {

    public static native void initEncoder(int numChannels, int sampleRate, int bitRate, int mode, int quality);
    public static native void destroyEncoder();
    public static native int encodeBuffer(byte[] input, int len_input, byte[] output, int len_output);
    
} 
