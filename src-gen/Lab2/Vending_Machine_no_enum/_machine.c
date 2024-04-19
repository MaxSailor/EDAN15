#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine_no_enum/Machine.h"
#include "_machine.h"
// *********** From the preamble, verbatim:
#line 6 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_no_enum.lf"
#include <string.h>
#line 9 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_no_enum/_machine.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _machinereaction_function_0(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_coin_t* coin = self->_lf_coin;
    int coin_width = self->_lf_coin_width; SUPPRESS_UNUSED_WARNING(coin_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    #line 19 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_no_enum.lf"
    switch(self -> Machine_mode) {
        case 0:
            lf_set(change, false);
            lf_set(beverage, 0);
            self -> Machine_mode = Payed;
        case 1:
            lf_set(change,false);
            lf_set(beverage, self -> bev);
            self -> Machine_mode = 0;
            self -> bev = 0;
        case Payed:
            lf_set(change, true);
            lf_set(beverage, 0);
            self -> Machine_mode = Payed;
    }
#line 37 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_no_enum/_machine.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _machinereaction_function_1(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_sel_t* sel = self->_lf_sel;
    int sel_width = self->_lf_sel_width; SUPPRESS_UNUSED_WARNING(sel_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    #line 37 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_no_enum.lf"
    switch(self -> Machine_mode) {
        case 0:
            lf_set(change, false);
            lf_set(beverage, 0);
            self -> Machine_mode = 1;
            self -> bev = sel -> value;
        case 1:
            lf_set(change,false);
            lf_set(beverage, 0);
            self -> Machine_mode = 1;
            self -> bev = sel -> value;
        case Payed:
            lf_set(change, false);
            lf_set(beverage, sel -> value);
            self -> Machine_mode = 0;
            self -> bev = 0;
    }
#line 65 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_no_enum/_machine.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _machinereaction_function_2(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_cancel_t* cancel = self->_lf_cancel;
    int cancel_width = self->_lf_cancel_width; SUPPRESS_UNUSED_WARNING(cancel_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    #line 57 "/Users/sailor/Developer/git/EDAN15/Lab2/Vending_Machine_no_enum.lf"
    switch(self -> Machine_mode) {
        case 0:
            lf_set(change, false);
            lf_set(beverage, 0);
            self -> Machine_mode = 0;
        case 1:
            lf_set(change,false);
            lf_set(beverage, 0);
            self -> Machine_mode = 0;
            self -> bev = 0;
        case Payed:
            lf_set(change, true);
            lf_set(beverage, 0);
            self -> Machine_mode = 0;
    }
#line 91 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_no_enum/_machine.c"
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
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _machinereaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _machinereaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__cancel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__cancel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__cancel_reactions[0] = &self->_lf__reaction_2;
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
    self->_lf__sel_reactions[0] = &self->_lf__reaction_1;
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
