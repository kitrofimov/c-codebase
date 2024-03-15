#pragma once
 #include <time.h>

#define TIMER_START(name) clock_t name = clock(), name##_diff
#define TIMER_STOP(name) name##_diff = clock() - name
#define TIMER_REPORT_S(name, type)  ((type) name##_diff / CLOCKS_PER_SEC)
#define TIMER_REPORT_MS(name, type) ((type) name##_diff * 1000 / CLOCKS_PER_SEC)
#define TIMER_REPORT_US(name, type) ((type) name##_diff * 1000000 / CLOCKS_PER_SEC)

