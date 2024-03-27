#ifndef _SOURCE_H
#define _SOURCE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_546501105_H
#define TOP_LEVEL_PREAMBLE_546501105_H
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
} _source_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _source_a_t;
typedef struct {
    struct self_base_t base;
    #line 5 "/Users/sailor/Developer/EDAN15/Lab1/lab1_3.lf"
    interval_t start;
    #line 5 "/Users/sailor/Developer/EDAN15/Lab1/lab1_3.lf"
    interval_t incr;
#line 44 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_3/_source.h"
    #line 7 "/Users/sailor/Developer/EDAN15/Lab1/lab1_3.lf"
    interval_t interval;
#line 47 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_3/_source.h"
    _source_a_t _lf_a;
    _source_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__a;
    reaction_t* _lf__a_reactions[1];
} _source_self_t;
_source_self_t* new__source();
#endif // _SOURCE_H
