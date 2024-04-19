#ifndef _OUTPUT_H
#define _OUTPUT_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1184735558_H
#define TOP_LEVEL_PREAMBLE_1184735558_H
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _output_change_t;
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
} _output_beverage_t;
typedef struct {
    struct self_base_t base;
#line 38 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_output.h"
#line 39 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_output.h"
    _output_change_t* _lf_change;
    // width of -2 indicates that it is not a multiport.
    int _lf_change_width;
    // Default input (in case it does not get connected)
    _output_change_t _lf_default__change;
    _output_beverage_t* _lf_beverage;
    // width of -2 indicates that it is not a multiport.
    int _lf_beverage_width;
    // Default input (in case it does not get connected)
    _output_beverage_t _lf_default__beverage;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__change;
    reaction_t* _lf__change_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__beverage;
    reaction_t* _lf__beverage_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _output_self_t;
_output_self_t* new__output();
#endif // _OUTPUT_H
