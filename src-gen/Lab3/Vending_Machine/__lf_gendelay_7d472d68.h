#ifndef __LF_GENDELAY_7D472D68_H
#define __LF_GENDELAY_7D472D68_H
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
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} __lf_gendelay_7d472d68_inp_t;
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
} __lf_gendelay_7d472d68_out_t;
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
} __lf_gendelay_7d472d68_act_t;
typedef struct {
    struct self_base_t base;
    interval_t delay;
#line 55 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/__lf_gendelay_7d472d68.h"
#line 56 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/__lf_gendelay_7d472d68.h"
    __lf_gendelay_7d472d68_act_t _lf_act;
    __lf_gendelay_7d472d68_inp_t* _lf_inp;
    // width of -2 indicates that it is not a multiport.
    int _lf_inp_width;
    // Default input (in case it does not get connected)
    __lf_gendelay_7d472d68_inp_t _lf_default__inp;
    __lf_gendelay_7d472d68_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__act;
    reaction_t* _lf__act_reactions[1];
    trigger_t _lf__inp;
    reaction_t* _lf__inp_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} __lf_gendelay_7d472d68_self_t;
__lf_gendelay_7d472d68_self_t* new___lf_gendelay_7d472d68();
#endif // __LF_GENDELAY_7D472D68_H
