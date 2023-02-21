# mp3lametest
编译通过lame转成MP3的so库
对其中三个文件做了一些小改动
- fft.c中47行将vector/lame_intrin.h这个头文件注释了或者去掉
- 修改set_get.h文件的24行的#include <lame.h>改为#include "lame.h"
- 将util.h文件的574行的”extern ieee754_float32_t fast_log2(ieee754_float32_t x);”
替换为 “extern float fast_log2(float x);”因为android下不支持该类型。

点击小锤子Make Project后，在build/intermediates/cmake/debug/obj中可以找到对应的so库
>该so库使用demo [mp3格式音频录制和播放](https://github.com/zone-yan/AudioRecordPlayDemo)
