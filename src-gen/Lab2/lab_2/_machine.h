#ifndef _MACHINE_H
#define _MACHINE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_688361537_H
#define TOP_LEVEL_PREAMBLE_688361537_H
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
} _machine_cancel_t;
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
} _machine_sel_t;
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
} _machine_coin_t;
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
} _machine_change_t;
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
} _machine_beverage_t;
typedef struct {
    struct self_base_t base;
    #line 4 "/Users/sailor/Developer/git/EDAN15/Lab2/lab_2.lf"
    int* stock;
#line 82 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/lab_2/_machine.h"
#line 83 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/lab_2/_machine.h"
    _machine_cancel_t* _lf_cancel;
    // width of -2 indicates that it is not a multiport.
    int _lf_cancel_width;
    // Default input (in case it does not get connected)
    _machine_cancel_t _lf_default__cancel;
    _machine_sel_t* _lf_sel;
    // width of -2 indicates that it is not a multiport.
    int _lf_sel_width;
    // Default input (in case it does not get connected)
    _machine_sel_t _lf_default__sel;
    _machine_coin_t* _lf_coin;
    // width of -2 indicates that it is not a multiport.
    int _lf_coin_width;
    // Default input (in case it does not get connected)
    _machine_coin_t _lf_default__coin;
    _machine_change_t _lf_change;
    int _lf_change_width;
    _machine_beverage_t _lf_beverage;
    int _lf_beverage_width;
    trigger_t _lf__cancel;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__sel;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__coin;
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _machine_self_t;
_machine_self_t* new__machine();
#endif // _MACHINE_H
