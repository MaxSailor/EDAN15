#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine/Display.h"
#include "_display.h"
// *********** From the preamble, verbatim:
#line 140 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
#include <string.h>
#line 9 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _displayreaction_function_0(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _display_text_t* text = self->_lf_text;
    int text_width = self->_lf_text_width; SUPPRESS_UNUSED_WARNING(text_width);
    _display_a_t* a = &self->_lf_a;
    #line 146 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    printf("%s", text -> value);
    lf_schedule(a, 5);
#line 23 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _displayreaction_function_1(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _display_a_t* a = &self->_lf_a;
    // Set the fields of the action struct to match the current trigger.
    a->is_present = (bool)self->_lf__a.status;
    a->has_value = ((self->_lf__a.tmplt.token) != NULL && (self->_lf__a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)a, (self->_lf__a.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    #line 151 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    printf("Display off. \n");
#line 39 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.c"
}
#include "include/api/set_undef.h"
_display_self_t* new__display() {
    _display_self_t* self = (_display_self_t*)_lf_new_reactor(sizeof(_display_self_t));
    self->_lf_a._base.trigger = &self->_lf__a;
    self->_lf_a.parent = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_text = &self->_lf_default__text;
    // Set the default source reactor pointer
    self->_lf_default__text._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _displayreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _displayreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
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
    self->_lf__text.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__text.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__text_reactions[0] = &self->_lf__reaction_0;
    self->_lf__text.reactions = &self->_lf__text_reactions[0];
    self->_lf__text.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__text.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__text.tmplt.type.element_size = sizeof(string);
    return self;
}
