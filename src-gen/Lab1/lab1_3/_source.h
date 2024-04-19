#ifndef _SOURCE_H
#define _SOURCE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1398010396_H
#define TOP_LEVEL_PREAMBLE_1398010396_H
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
#line 40 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_3/_source.h"
#line 41 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_3/_source.h"
    _source_a_t _lf_a;
    _source_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__a;
} _source_self_t;
_source_self_t* new__source();
#endif // _SOURCE_H
