#ifndef KRON_H_
#define KRON_H_

#include <stdint.h>

#ifdef _WIN32
    #include "kron_win32.h"
#endif


/* Initializes neccessary state. May be a no-op.
 */
void kron_init(void);


/* Retrieves time in precision defined by `kron_freq()`.
 */
int64_t kron_time(void);


/* Retrieves precision of the `kron_time()` function.
 * Is static for the duration of the program.
 */
int64_t kron_freq(void);


/* Converts result of `kron_time()` to nanoseconds.
 */
int64_t kron_to_nano(int64_t time);


#endif // KRON_H_
