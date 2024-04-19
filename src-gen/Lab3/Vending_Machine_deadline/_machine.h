#ifndef _MACHINE_H
#define _MACHINE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_36484796_H
#define TOP_LEVEL_PREAMBLE_36484796_H
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
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _machine_displayed_t;
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
} _machine_text_t;
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
} _machine_dead_t;
typedef struct {
    struct self_base_t base;
    #line 4 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    int* stock;
#line 124 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_machine.h"
    #line 24 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    int Machine_mode;
    #line 25 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    int bev;
    #line 26 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    string charBuffer;
#line 131 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_machine.h"
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
    _machine_displayed_t* _lf_displayed;
    // width of -2 indicates that it is not a multiport.
    int _lf_displayed_width;
    // Default input (in case it does not get connected)
    _machine_displayed_t _lf_default__displayed;
    _machine_change_t _lf_change;
    int _lf_change_width;
    _machine_beverage_t _lf_beverage;
    int _lf_beverage_width;
    _machine_text_t _lf_text;
    int _lf_text_width;
    _machine_dead_t _lf_dead;
    int _lf_dead_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__cancel;
    reaction_t* _lf__cancel_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__sel;
    reaction_t* _lf__sel_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__coin;
    reaction_t* _lf__coin_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__displayed;
    reaction_t* _lf__displayed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _machine_self_t;
_machine_self_t* new__machine();
#endif // _MACHINE_H
