#ifndef _SINK_H
#define _SINK_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1399883754_H
#define TOP_LEVEL_PREAMBLE_1399883754_H
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _sink_in_t;
typedef struct {
    struct self_base_t base;
#line 24 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/_sink.h"
#line 25 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/_sink.h"
    _sink_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _sink_in_t _lf_default__in;
    reaction_t _lf__reaction_0;
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _sink_self_t;
_sink_self_t* new__sink();
#endif // _SINK_H
