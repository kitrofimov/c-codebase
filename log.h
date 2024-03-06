#pragma once
#include <stdio.h>

// memory
// debug
// info
// warn
// error
// fatal

#if defined(NDEBUG)
    #define LOGM(...)
    #define LOGD(...)
    #define LOGI(...) fprintf(stderr, "I: "__VA_ARGS__)
    #define LOGW(...) fprintf(stderr, "W: "__VA_ARGS__)
    #define LOGE(...) fprintf(stderr, "E: "__VA_ARGS__)
    #define LOGF(...) fprintf(stderr, "F: "__VA_ARGS__)
#elif defined(LOG_MEMORY)
    #define LOGM(...) fprintf(stderr, "M: "__VA_ARGS__) 
    #define LOGD(...) fprintf(stderr, "D: "__VA_ARGS__)
    #define LOGI(...) fprintf(stderr, "I: "__VA_ARGS__)
    #define LOGW(...) fprintf(stderr, "W: "__VA_ARGS__)
    #define LOGE(...) fprintf(stderr, "E: "__VA_ARGS__)
    #define LOGF(...) fprintf(stderr, "F: "__VA_ARGS__)
#else
    #define LOGM(...)
    #define LOGD(...) fprintf(stderr, "D: "__VA_ARGS__)
    #define LOGI(...) fprintf(stderr, "I: "__VA_ARGS__)
    #define LOGW(...) fprintf(stderr, "W: "__VA_ARGS__)
    #define LOGE(...) fprintf(stderr, "E: "__VA_ARGS__)
    #define LOGF(...) fprintf(stderr, "F: "__VA_ARGS__)
#endif
