#include "kron.h"


kron_win32_t kron_win32;

void kron_init(void)
{
    LARGE_INTEGER freq;

    if (!QueryPerformanceFrequency(&freq)) {
        fprintf(stderr, "QueryPerformanceFrequency(): (%d)\n", GetLastError());
        exit(666);
    }

    kron_win32.mul = (1000 * 1000 * 1000) / freq.QuadPart;
    kron_win32.freq = freq.QuadPart;
}


int64_t kron_to_nano(int64_t time)
{
    return time * kron_win32.mul;
}


int64_t kron_freq(void)
{
    return kron_win32.freq;
}
