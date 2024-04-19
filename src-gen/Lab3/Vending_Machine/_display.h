#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_502157791_H
#define TOP_LEVEL_PREAMBLE_502157791_H
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
} _display_text_t;
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
} _display_a_t;
typedef struct {
    struct self_base_t base;
#line 40 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.h"
#line 41 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.h"
    _display_a_t _lf_a;
    _display_text_t* _lf_text;
    // width of -2 indicates that it is not a multiport.
    int _lf_text_width;
    // Default input (in case it does not get connected)
    _display_text_t _lf_default__text;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__a;
    reaction_t* _lf__a_reactions[1];
    trigger_t _lf__text;
    reaction_t* _lf__text_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _display_self_t;
_display_self_t* new__display();
#endif // _DISPLAY_H
