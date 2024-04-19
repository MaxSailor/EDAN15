#ifndef _INPUT_H
#define _INPUT_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_270365049_H
#define TOP_LEVEL_PREAMBLE_270365049_H
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
} _input_cancel_t;
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
} _input_sel_t;
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
} _input_coin_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _input_a_t;
typedef struct {
    struct self_base_t base;
#line 68 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_input.h"
    #line 44 "/Users/sailor/Developer/git/EDAN15/Lab3/vm_extra.lf"
    lf_thread_t thread_id;
#line 71 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_input.h"
    _input_a_t _lf_a;
    _input_cancel_t _lf_cancel;
    int _lf_cancel_width;
    _input_sel_t _lf_sel;
    int _lf_sel_width;
    _input_coin_t _lf_coin;
    int _lf_coin_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__a;
    reaction_t* _lf__a_reactions[1];
} _input_self_t;
_input_self_t* new__input();
#endif // _INPUT_H
