#ifndef KRON_WIN32_H_
#define KRON_WIN32_H_

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int64_t mul;
    int64_t freq;
} kron_win32_t;

extern kron_win32_t kron_win32;


static inline int64_t kron_time(void)
{
    LARGE_INTEGER ticks;

    if (!QueryPerformanceCounter(&ticks)) {
        fprintf(stderr, "QueryPerformanceCounter(): (%d)\n", GetLastError());
        exit(666);
    }

    return ticks.QuadPart;
}


#endif // KRON_WIN32_H_
