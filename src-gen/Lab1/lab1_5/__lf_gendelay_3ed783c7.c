#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab1_5/_lf_GenDelay_3ed783c7.h"
#include "__lf_gendelay_3ed783c7.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void __lf_gendelay_3ed783c7reaction_function_0(void* instance_args) {
    __lf_gendelay_3ed783c7_self_t* self = (__lf_gendelay_3ed783c7_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    __lf_gendelay_3ed783c7_act_t* act = &self->_lf_act;
    // Set the fields of the action struct to match the current trigger.
    act->is_present = (bool)self->_lf__act.status;
    act->has_value = ((self->_lf__act.tmplt.token) != NULL && (self->_lf__act.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)act, (self->_lf__act.tmplt.token));
    if (act->has_value) {
        act->value = *(int*)(self->_lf__act.tmplt.token)->value;
    }
    lf_critical_section_exit(self->base.environment);
    __lf_gendelay_3ed783c7_out_t* out = &self->_lf_out;
    lf_set(out, act->value);
#line 24 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/__lf_gendelay_3ed783c7.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void __lf_gendelay_3ed783c7reaction_function_1(void* instance_args) {
    __lf_gendelay_3ed783c7_self_t* self = (__lf_gendelay_3ed783c7_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    __lf_gendelay_3ed783c7_inp_t* inp = self->_lf_inp;
    int inp_width = self->_lf_inp_width; SUPPRESS_UNUSED_WARNING(inp_width);
    __lf_gendelay_3ed783c7_act_t* act = &self->_lf_act;
    lf_schedule_copy(act, 0, &inp->value, 1);  // Length is 1.
#line 34 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_5/__lf_gendelay_3ed783c7.c"
}
#include "include/api/set_undef.h"
__lf_gendelay_3ed783c7_self_t* new___lf_gendelay_3ed783c7() {
    __lf_gendelay_3ed783c7_self_t* self = (__lf_gendelay_3ed783c7_self_t*)_lf_new_reactor(sizeof(__lf_gendelay_3ed783c7_self_t));
    self->_lf_act._base.trigger = &self->_lf__act;
    self->_lf_act.parent = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_inp = &self->_lf_default__inp;
    // Set the default source reactor pointer
    self->_lf_default__inp._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = __lf_gendelay_3ed783c7reaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = __lf_gendelay_3ed783c7reaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__act.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__act.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__act_reactions[0] = &self->_lf__reaction_0;
    self->_lf__act.reactions = &self->_lf__act_reactions[0];
    self->_lf__act.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__act.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__act.is_physical = false;
    
    self->_lf__act.tmplt.type.element_size = sizeof(int);
    self->_lf_act.type.element_size = sizeof(int);
    self->_lf__inp.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__inp.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__inp_reactions[0] = &self->_lf__reaction_1;
    self->_lf__inp.reactions = &self->_lf__inp_reactions[0];
    self->_lf__inp.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__inp.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__inp.tmplt.type.element_size = sizeof(int);
    return self;
}
