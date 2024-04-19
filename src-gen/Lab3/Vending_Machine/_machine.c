#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine/Machine.h"
#include "_machine.h"
// *********** From the preamble, verbatim:
#line 7 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
#include <string.h>
enum machine_mode {
    Idle = 0,
    Selected = 1,
    Payed = 2
};
char buf[100];
#line 15 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_machine.c"

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
    _machine_text_t* text = &self->_lf_text;
    reactor_mode_t* On = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_On_change_type = reset_transition;
    #line 33 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    lf_set_mode(On);
    sprintf(buf, "Powering on.\n");
    lf_set(text, buf);
#line 36 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_machine.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _machinereaction_function_1(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_coin_t* coin = self->_lf_coin;
    int coin_width = self->_lf_coin_width; SUPPRESS_UNUSED_WARNING(coin_width);
    _machine_sel_t* sel = self->_lf_sel;
    int sel_width = self->_lf_sel_width; SUPPRESS_UNUSED_WARNING(sel_width);
    _machine_cancel_t* cancel = self->_lf_cancel;
    int cancel_width = self->_lf_cancel_width; SUPPRESS_UNUSED_WARNING(cancel_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    _machine_text_t* text = &self->_lf_text;
    #line 41 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    if(coin -> is_present){
    //printf("[DEBUG] Coin detected. State: %d \n", self -> Machine_mode);
        switch(self -> Machine_mode) {
            case Idle:
                self -> Machine_mode = Payed;
                sprintf(buf,"Coin recieved. Please make a selection.\n");
                lf_set(text, buf);
                break;
            case Selected:
                if(self -> stock[self  -> bev] != 0){
                    lf_set(beverage, self -> bev);
                    self -> stock[self  -> bev]--;
                    self -> Machine_mode = Idle;
                    sprintf(buf, "Coin recieved. Please take your beverage.\n");
                    lf_set(text, buf);
                }else{
                    self -> Machine_mode = Selected;
                    sprintf(buf, "Coin recieved. There are no more of that bevereage, please choose something else.\n");
                    lf_set(text, buf);
                }
    
                break;
            case Payed:
                lf_set(change, true);
                self -> Machine_mode = Payed;
                sprintf(buf,"Coin recieved. Coin already in machine. Please pick up change.\n");
                lf_set(text, buf);
                break;
        }
    }
    
    if(sel -> is_present){
        //printf("[DEBUG] Selection detected. State: %d \n", self -> Machine_mode);
        switch(self -> Machine_mode) {
            case Idle:
                if(sel -> value <= 2 && sel -> value >= 0){
                    self -> Machine_mode = Selected;
                    self -> bev = sel -> value;
                    sprintf(buf, "Selection made : %d. Please put in a coin. \n", sel -> value);
                    lf_set(text, buf);
                }else{
                    self -> Machine_mode = Idle;
                    sprintf(buf, "Not a viable selection. Please select again.\n");
                    lf_set(text, buf);
                }
                break;
            case Selected:
                if(sel -> value <= 2 && sel -> value >= 0){
                    self -> Machine_mode = Selected;
                    self -> bev = sel -> value;
                    sprintf(buf, "Selection changed : %d. Please put in a coin. \n", sel -> value);
                    lf_set(text, buf);
                }else{
                    self -> Machine_mode = Idle;
                    sprintf(buf, "Not a viable selection. Please select again.\n");
                    lf_set(text, buf);
                }
                break;
            case Payed:
                if(sel -> value <= 2 && sel -> value >= 0){
                    if(self -> stock[sel -> value] != 0){
                        lf_set(beverage, sel -> value);
                        self -> stock[sel  -> value]--;
                        self -> Machine_mode = Idle;
                        self -> bev = 0;
                        sprintf(buf, "Selection made : %d. Please pick up your beverage. \n", sel -> value);
                        lf_set(text, buf);
                    }else{
                        self -> Machine_mode = Payed;
                        sprintf(buf, "Beverage out of stock. Please select again. \n");
                        lf_set(text, buf);
                    }
                }else{
                    self -> Machine_mode = Payed;
                    sprintf(buf, "Not a viable selection. Please select again. \n");
                    lf_set(text, buf);
                }
                break;
        }
    
    }
    
    if(cancel -> is_present){
    //printf("[DEBUG] Cancellation detected. State: %d \n", self -> Machine_mode);
    switch(self -> Machine_mode) {
            case Idle:
                self -> Machine_mode = Idle;
                break;
            case Selected:
                self -> Machine_mode = Idle;
                self -> bev = 0;
                sprintf(buf, "Purchase canceled. \n");
                lf_set(text, buf);
                break;
            case Payed:
                lf_set(change, true);
                sprintf(buf, "Purchase canceled. Please pick up change.\n");
                lf_set(text, buf);
                self -> Machine_mode = Idle;
                break;
        }
    }
#line 154 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_machine.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _machinereaction_function_2(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _machine_display_off_t* display_off = self->_lf_display_off;
    int display_off_width = self->_lf_display_off_width; SUPPRESS_UNUSED_WARNING(display_off_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_a_t* a = &self->_lf_a;
    #line 146 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    lf_schedule(a, SECS(60));
    if(self -> Machine_mode == Payed){
        lf_set(change, true);
        self -> Machine_mode = 0;
    }
#line 170 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_machine.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _machinereaction_function_3(void* instance_args) {
    _machine_self_t* self = (_machine_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _machine_a_t* a = &self->_lf_a;
    // Set the fields of the action struct to match the current trigger.
    a->is_present = (bool)self->_lf__a.status;
    a->has_value = ((self->_lf__a.tmplt.token) != NULL && (self->_lf__a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)a, (self->_lf__a.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    reactor_mode_t* Off = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_Off_change_type = reset_transition;
    _machine_text_t* text = &self->_lf_text;
    #line 154 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    lf_set_mode(Off);
    sprintf(buf, "Powering down. \n");
    lf_set(text, buf);
#line 191 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_machine.c"
}
#include "include/api/set_undef.h"
_machine_self_t* new__machine() {
    _machine_self_t* self = (_machine_self_t*)_lf_new_reactor(sizeof(_machine_self_t));
    self->_lf_a._base.trigger = &self->_lf__a;
    self->_lf_a.parent = (self_base_t*)self;
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
    // Set input by default to an always absent default input.
    self->_lf_display_off = &self->_lf_default__display_off;
    // Set the default source reactor pointer
    self->_lf_default__display_off._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _machinereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = &self->_lf__modes[0];
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _machinereaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = &self->_lf__modes[1];
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _machinereaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = &self->_lf__modes[1];
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _machinereaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    self->_lf__a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__a_reactions[0] = &self->_lf__reaction_3;
    self->_lf__a.reactions = &self->_lf__a_reactions[0];
    self->_lf__a.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__a.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__a.is_physical = false;
    
    self->_lf__a.tmplt.type.element_size = 0;
    self->_lf_a.type.element_size = 0;
    self->_lf__cancel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__cancel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__cancel_reactions[0] = &self->_lf__reaction_0;
    self->_lf__cancel_reactions[1] = &self->_lf__reaction_1;
    self->_lf__cancel.reactions = &self->_lf__cancel_reactions[0];
    self->_lf__cancel.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__cancel.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__cancel.tmplt.type.element_size = sizeof(bool);
    self->_lf__sel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__sel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__sel_reactions[0] = &self->_lf__reaction_0;
    self->_lf__sel_reactions[1] = &self->_lf__reaction_1;
    self->_lf__sel.reactions = &self->_lf__sel_reactions[0];
    self->_lf__sel.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__sel.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__sel.tmplt.type.element_size = sizeof(int);
    self->_lf__coin.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__coin.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__coin_reactions[0] = &self->_lf__reaction_0;
    self->_lf__coin_reactions[1] = &self->_lf__reaction_1;
    self->_lf__coin.reactions = &self->_lf__coin_reactions[0];
    self->_lf__coin.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__coin.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__coin.tmplt.type.element_size = sizeof(bool);
    self->_lf__display_off.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__display_off.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__display_off_reactions[0] = &self->_lf__reaction_2;
    self->_lf__display_off.reactions = &self->_lf__display_off_reactions[0];
    self->_lf__display_off.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__display_off.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__display_off.tmplt.type.element_size = sizeof(int);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "Off";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "On";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
