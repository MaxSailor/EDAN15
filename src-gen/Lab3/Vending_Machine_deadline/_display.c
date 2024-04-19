#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine_deadline/Display.h"
#include "_display.h"
// *********** From the preamble, verbatim:
#line 149 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
#include <string.h>
#line 9 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_display.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _displayreaction_function_0(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _display_text_t* text = self->_lf_text;
    int text_width = self->_lf_text_width; SUPPRESS_UNUSED_WARNING(text_width);
    _display_dead_t* dead = self->_lf_dead;
    int dead_width = self->_lf_dead_width; SUPPRESS_UNUSED_WARNING(dead_width);
    _display_displayed_t* displayed = &self->_lf_displayed;
    #line 160 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    printf("[DISPLAY] %s", text -> value);
    self -> count = 0;
    self -> display_on = true;
    lf_set(displayed, 0);
#line 27 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_display.c"
}
void _display_deadline_function0(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _display_text_t* text = self->_lf_text;
    int text_width = self->_lf_text_width; SUPPRESS_UNUSED_WARNING(text_width);
    _display_dead_t* dead = self->_lf_dead;
    int dead_width = self->_lf_dead_width; SUPPRESS_UNUSED_WARNING(dead_width);
    _display_displayed_t* displayed = &self->_lf_displayed;
    #line 166 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine_deadline.lf"
    printf("[DISPLAY] Display off. \n");
#line 38 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine_deadline/_display.c"
}
#include "include/api/set_undef.h"
_display_self_t* new__display() {
    _display_self_t* self = (_display_self_t*)_lf_new_reactor(sizeof(_display_self_t));
    // Set input by default to an always absent default input.
    self->_lf_text = &self->_lf_default__text;
    // Set the default source reactor pointer
    self->_lf_default__text._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_dead = &self->_lf_default__dead;
    // Set the default source reactor pointer
    self->_lf_default__dead._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _displayreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = &_display_deadline_function0;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
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
    self->_lf__dead.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__dead.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__dead_reactions[0] = &self->_lf__reaction_0;
    self->_lf__dead.reactions = &self->_lf__dead_reactions[0];
    self->_lf__dead.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__dead.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__dead.tmplt.type.element_size = sizeof(int);
    return self;
}
