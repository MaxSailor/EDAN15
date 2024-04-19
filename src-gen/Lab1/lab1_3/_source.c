#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab1_3/Source.h"
#include "_source.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _sourcereaction_function_0(void* instance_args) {
    _source_self_t* self = (_source_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _source_out_t* out = &self->_lf_out;
    #line 11 "/Users/sailor/Developer/git/EDAN15/Lab1/lab1_3.lf"
    instant_t elapsed_logical_time = lf_time_logical_elapsed();
    lf_set(out, 2);
#line 15 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_3/_source.c"
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
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__a.is_physical = false;
    
    self->_lf__a.tmplt.type.element_size = 0;
    self->_lf_a.type.element_size = 0;
    return self;
}
