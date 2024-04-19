#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/vm_extra/Output.h"
#include "_output.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _outputreaction_function_0(void* instance_args) {
    _output_self_t* self = (_output_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _output_beverage_t* beverage = self->_lf_beverage;
    int beverage_width = self->_lf_beverage_width; SUPPRESS_UNUSED_WARNING(beverage_width);
    #line 8 "/Users/sailor/Developer/git/EDAN15/Lab2/vm_extra.lf"
    printf("[OUTPUT] Got a can of %d\n",beverage->value);
#line 15 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_state_check_first/_output.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _outputreaction_function_1(void* instance_args) {
    _output_self_t* self = (_output_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _output_change_t* change = self->_lf_change;
    int change_width = self->_lf_change_width; SUPPRESS_UNUSED_WARNING(change_width);
    #line 12 "/Users/sailor/Developer/git/EDAN15/Lab2/vm_extra.lf"
    printf("[OUTPUT] Got the coin back.\n");
#line 25 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/Vending_Machine_state_check_first/_output.c"
}
#include "include/api/set_undef.h"
_output_self_t* new__output() {
    _output_self_t* self = (_output_self_t*)_lf_new_reactor(sizeof(_output_self_t));
    // Set input by default to an always absent default input.
    self->_lf_change = &self->_lf_default__change;
    // Set the default source reactor pointer
    self->_lf_default__change._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_beverage = &self->_lf_default__beverage;
    // Set the default source reactor pointer
    self->_lf_default__beverage._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _outputreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _outputreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__change.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__change.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__change_reactions[0] = &self->_lf__reaction_1;
    self->_lf__change.reactions = &self->_lf__change_reactions[0];
    self->_lf__change.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__change.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__change.tmplt.type.element_size = sizeof(bool);
    self->_lf__beverage.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__beverage.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__beverage_reactions[0] = &self->_lf__reaction_0;
    self->_lf__beverage.reactions = &self->_lf__beverage_reactions[0];
    self->_lf__beverage.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__beverage.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__beverage.tmplt.type.element_size = sizeof(int);
    return self;
}
