#ifndef _STRINGLN_H
#define _STRINGLN_H
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
} _stringln_in_int_t;
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
} _stringln_out_int_t;
typedef struct {
    struct self_base_t base;
#line 66 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/_stringln.h"
    #line 35 "/Users/sailor/Developer/EDAN15/Lab1/lab1_5.lf"
    int total;
#line 69 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/_stringln.h"
    _stringln_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _stringln_in_t _lf_default__in;
    _stringln_in_int_t* _lf_in_int;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_int_width;
    // Default input (in case it does not get connected)
    _stringln_in_int_t _lf_default__in_int;
    _stringln_out_t _lf_out;
    int _lf_out_width;
    _stringln_out_int_t _lf_out_int;
    int _lf_out_int_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__in_int;
    reaction_t* _lf__in_int_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _stringln_self_t;
_stringln_self_t* new__stringln();
#endif // _STRINGLN_H
