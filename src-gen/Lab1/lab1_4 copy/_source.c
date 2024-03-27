#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab1_4 copy/Source.h"
#include "_source.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _sourcereaction_function_0(void* instance_args) {
    _source_self_t* self = (_source_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _source_a_t* a = &self->_lf_a;
    #line 11 "/Users/sailor/Developer/EDAN15/Lab1/lab1_4%20copy.lf"
    lf_schedule(a, self-> start);
#line 14 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_4 copy/_source.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _sourcereaction_function_1(void* instance_args) {
    _source_self_t* self = (_source_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _source_a_t* a = &self->_lf_a;
    // Set the fields of the action struct to match the current trigger.
    a->is_present = (bool)self->_lf__a.status;
    a->has_value = ((self->_lf__a.tmplt.token) != NULL && (self->_lf__a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)a, (self->_lf__a.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    _source_out_t* out = &self->_lf_out;
    #line 15 "/Users/sailor/Developer/EDAN15/Lab1/lab1_4%20copy.lf"
    instant_t elapsed_logical_time = lf_time_logical_elapsed();
    self -> interval += self -> incr;
    lf_set(out, "hej");
    lf_schedule(a, self->interval);
#line 34 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_4 copy/_source.c"
}
#include "include/api/set_undef.h"
_source_self_t* new__source() {
    _source_self_t* self = (_source_self_t*)_lf_new_reactor(sizeof(_source_self_t));
    self->_lf_a._base.trigger = &self->_lf__a;
    self->_lf_a.parent = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _sourcereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _sourcereaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__a_reactions[0] = &self->_lf__reaction_1;
    self->_lf__a.reactions = &self->_lf__a_reactions[0];
    self->_lf__a.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__a.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__a.is_physical = false;
    
    self->_lf__a.tmplt.type.element_size = 0;
    self->_lf_a.type.element_size = 0;
    return self;
}
