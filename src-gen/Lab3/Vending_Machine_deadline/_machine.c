#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine_deadline/Machine.h"
#include "_machine.h"
// *********** From the preamble, verbatim:
#line 6 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
#include <string.h>
enum machine_mode {
    Idle = 0, 
    Selected = 1, 
    Payed = 2
};
char buf[100];
#line 15 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_machine.c"

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
    _machine_displayed_t* displayed = self->_lf_displayed;
    int displayed_width = self->_lf_displayed_width; SUPPRESS_UNUSED_WARNING(displayed_width);
    _machine_change_t* change = &self->_lf_change;
    _machine_beverage_t* beverage = &self->_lf_beverage;
    _machine_text_t* text = &self->_lf_text;
    _machine_dead_t* dead = &self->_lf_dead;
    #line 31 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    lf_set(dead, 0);
    instant_t start_time = lf_time_logical_elapsed();
    bool triggered = true;
    while(lf_time_logical_elapsed() - start_time < 100000000 && triggered){
        if(coin -> is_present){
            triggered = false;
        printf("[DEBUG] Coin detected. State: %d \n", self -> Machine_mode);
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
            triggered = false;
            printf("[DEBUG] Selection detected. State: %d \n", self -> Machine_mode);
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
            triggered = false;
        printf("[DEBUG] Cancellation detected. State: %d \n", self -> Machine_mode);
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
    }
    printf("[DEBUG] Timer done");
#line 146 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_machine.c"
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
    // Set input by default to an always absent default input.
    self->_lf_displayed = &self->_lf_default__displayed;
    // Set the default source reactor pointer
    self->_lf_default__displayed._base.source_reactor = (self_base_t*)self;
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
    self->_lf__displayed.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__displayed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__displayed_reactions[0] = &self->_lf__reaction_0;
    self->_lf__displayed.reactions = &self->_lf__displayed_reactions[0];
    self->_lf__displayed.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__displayed.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__displayed.tmplt.type.element_size = sizeof(int);
    return self;
}
