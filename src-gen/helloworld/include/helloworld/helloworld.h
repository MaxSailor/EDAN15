#ifndef _helloworld_main_H
#define _helloworld_main_H
#ifndef _HELLOWORLD_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_235955970_H
#define TOP_LEVEL_PREAMBLE_235955970_H
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct helloworld_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} helloworld_self_t;
#endif
#endif
