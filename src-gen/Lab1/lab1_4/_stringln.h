#ifndef _STRINGLN_H
#define _STRINGLN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1250239514_H
#define TOP_LEVEL_PREAMBLE_1250239514_H
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _stringln_in_t;
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
} _stringln_out_t;
typedef struct {
    struct self_base_t base;
#line 38 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_4/_stringln.h"
#line 39 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_4/_stringln.h"
    _stringln_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _stringln_in_t _lf_default__in;
    _stringln_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _stringln_self_t;
_stringln_self_t* new__stringln();
#endif // _STRINGLN_H
