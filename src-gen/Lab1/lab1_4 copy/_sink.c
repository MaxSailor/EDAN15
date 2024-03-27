#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab1_4 copy/Sink.h"
#include "_sink.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _sinkreaction_function_0(void* instance_args) {
    _sink_self_t* self = (_sink_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _sink_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    #line 27 "/Users/sailor/Developer/EDAN15/Lab1/lab1_4%20copy.lf"
    printf("%d \n", in -> value);
#line 15 "/Users/sailor/Developer/EDAN15/src-gen/Lab1/lab1_4 copy/_sink.c"
}
#include "include/api/set_undef.h"
_sink_self_t* new__sink() {
    _sink_self_t* self = (_sink_self_t*)_lf_new_reactor(sizeof(_sink_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _sinkreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_reactions[0] = &self->_lf__reaction_0;
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    self->_lf__in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(int);
    return self;
}
