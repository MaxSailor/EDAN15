#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab1_5/Stringln.h"
#include "_stringln.h"
// *********** From the preamble, verbatim:
#line 33 "/Users/sailor/Developer/git/EDAN15/Lab1/lab1_5.lf"
#include <string.h>
#line 9 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_5/_stringln.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _stringlnreaction_function_0(void* instance_args) {
    _stringln_self_t* self = (_stringln_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _stringln_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    _stringln_out_t* out = &self->_lf_out;
    #line 43 "/Users/sailor/Developer/git/EDAN15/Lab1/lab1_5.lf"
    //printf("%s \n", in -> value);
    
    lf_set(out, strlen(in->value));
    self -> total += strlen(in->value);
#line 25 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_5/_stringln.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _stringlnreaction_function_1(void* instance_args) {
    _stringln_self_t* self = (_stringln_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _stringln_in_int_t* in_int = self->_lf_in_int;
    int in_int_width = self->_lf_in_int_width; SUPPRESS_UNUSED_WARNING(in_int_width);
    _stringln_out_int_t* out_int = &self->_lf_out_int;
    #line 50 "/Users/sailor/Developer/git/EDAN15/Lab1/lab1_5.lf"
    lf_set(out_int, in_int -> value);
#line 36 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_5/_stringln.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _stringlnreaction_function_2(void* instance_args) {
    _stringln_self_t* self = (_stringln_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 54 "/Users/sailor/Developer/git/EDAN15/Lab1/lab1_5.lf"
    printf("%d \n", self -> total);
#line 45 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab1/lab1_5/_stringln.c"
}
#include "include/api/set_undef.h"
_stringln_self_t* new__stringln() {
    _stringln_self_t* self = (_stringln_self_t*)_lf_new_reactor(sizeof(_stringln_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_in_int = &self->_lf_default__in_int;
    // Set the default source reactor pointer
    self->_lf_default__in_int._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _stringlnreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _stringlnreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _stringlnreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__shutdown.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__shutdown_reactions[0] = &self->_lf__reaction_2;
    self->_lf__shutdown.last_tag = NEVER_TAG;
    self->_lf__shutdown.reactions = &self->_lf__shutdown_reactions[0];
    self->_lf__shutdown.number_of_reactions = 1;
    self->_lf__shutdown.is_timer = false;
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
    self->_lf__in.tmplt.type.element_size = sizeof(string);
    self->_lf__in_int.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in_int.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_int_reactions[0] = &self->_lf__reaction_1;
    self->_lf__in_int.reactions = &self->_lf__in_int_reactions[0];
    self->_lf__in_int.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in_int.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in_int.tmplt.type.element_size = sizeof(int);
    return self;
}
