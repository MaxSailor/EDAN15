#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine_state_check_first/Machine.h"
#include "_machine.h"
// *********** From the preamble, verbatim:
#line 6 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_state_check_first.lf"
enum machine_mode {
    Idle = 0, 
    Selected = 1, 
    Payed = 2};
#line 12 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_state_check_first/_machine.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _machinereaction_function_0(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_coin_t* coin = self->_lf_coin;
    int coin_width = self->_lf_coin_width; SUPPRESS_UNUSED_WARNING(coin_width);
    _machine_sel_t* sel = self->_lf_sel;
    int sel_width = self->_lf_sel_width; SUPPRESS_UNUSED_WARNING(sel_width);
    _machine_cancel_t* cancel = self->_lf_cancel;
    int cancel_width = self->_lf_cancel_width; SUPPRESS_UNUSED_WARNING(cancel_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    #line 22 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_state_check_first.lf"
    switch(self -> Machine_mode) {
        case Idle:
            if(coin -> is_present){
                printf("[DEBUG] Coin detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Payed;
            }
            if(sel -> is_present){
                printf("[DEBUG] Select detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Selected;
                self -> bev = sel -> value;
            }
            if(cancel -> is_present){
                printf("[DEBUG] Cancel detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Idle;
            }
            break;
        case Selected:
            if(coin -> is_present){
                printf("[DEBUG] Coin detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Idle;
                lf_set(beverage, self -> bev);
            }
            if(sel -> is_present){
                printf("[DEBUG] Select detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Selected;
                self -> bev = sel -> value;
            }
            if(cancel -> is_present){
                printf("[DEBUG] Cancel detected. State: %d \n", self -> Machine_mode);
                self -> bev = 0;
                self -> Machine_mode = Idle;
            }
            break;
        case Payed:
            if(coin -> is_present){
                printf("[DEBUG] Coin detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Payed;
                lf_set(change, true);
            }
            if(sel -> is_present){
                printf("[DEBUG] Select detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Idle;
                lf_set(beverage, sel -> value);
            }
            if(cancel -> is_present){
                printf("[DEBUG] Cancel detected. State: %d \n", self -> Machine_mode);
                self -> Machine_mode = Idle;
                lf_set(change, true);
            }
            break;
    }
#line 80 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_state_check_first/_machine.c"
}
#include "include/api/set_undef.h"
_machine_self_t* new__machine() {
    _machine_self_t* self = (_machine_self_t*)_lf_new_reactor(sizeof(_machine_self_t));
    // Set input by default to an always absent default input.
    self->_lf_cancel = &self->_lf_default__cancel;
    // Set the default source reactor pointer
    self->_lf_default__cancel._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_sel = &self->_lf_default__sel;
    // Set the default source reactor pointer
    self->_lf_default__sel._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_coin = &self->_lf_default__coin;
    // Set the default source reactor pointer
    self->_lf_default__coin._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _machinereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__cancel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__cancel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__cancel_reactions[0] = &self->_lf__reaction_0;
    self->_lf__cancel.reactions = &self->_lf__cancel_reactions[0];
    self->_lf__cancel.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__cancel.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__cancel.tmplt.type.element_size = sizeof(bool);
    self->_lf__sel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__sel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__sel_reactions[0] = &self->_lf__reaction_0;
    self->_lf__sel.reactions = &self->_lf__sel_reactions[0];
    self->_lf__sel.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__sel.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__sel.tmplt.type.element_size = sizeof(int);
    self->_lf__coin.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__coin.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__coin_reactions[0] = &self->_lf__reaction_0;
    self->_lf__coin.reactions = &self->_lf__coin_reactions[0];
    self->_lf__coin.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__coin.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__coin.tmplt.type.element_size = sizeof(bool);
    return self;
}
