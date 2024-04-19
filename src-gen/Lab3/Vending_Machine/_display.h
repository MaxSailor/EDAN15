#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1403888540_H
#define TOP_LEVEL_PREAMBLE_1403888540_H
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
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _display_display_off_t;
typedef struct {
    struct self_base_t base;
#line 38 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.h"
    #line 168 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    int count;
    #line 169 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    bool display_on;
#line 43 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.h"
    _display_text_t* _lf_text;
    // width of -2 indicates that it is not a multiport.
    int _lf_text_width;
    // Default input (in case it does not get connected)
    _display_text_t _lf_default__text;
    _display_display_off_t _lf_display_off;
    int _lf_display_off_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__text;
    reaction_t* _lf__text_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _display_self_t;
_display_self_t* new__display();
#endif // _DISPLAY_H
