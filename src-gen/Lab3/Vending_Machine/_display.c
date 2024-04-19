#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine/Display.h"
#include "_display.h"
// *********** From the preamble, verbatim:
#line 163 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
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
    #line 172 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    printf("[DISPLAY] %s", text -> value);
    self -> count = 0;
    self -> display_on = true;
#line 23 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _displayreaction_function_1(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _display_display_off_t* display_off = &self->_lf_display_off;
    #line 178 "/Users/sailor/Developer/git/EDAN15/Lab3/Vending_Machine.lf"
    if(self -> count >= 50){
        if(self -> display_on){
            printf("[DISPLAY] Display off. \n");
            self -> display_on = false;
            lf_set(display_off, 0);
        }
        self -> count = 0;
    }else{
        self -> count++;
    }
#line 41 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab3/Vending_Machine/_display.c"
}
#include "include/api/set_undef.h"
_display_self_t* new__display() {
    _display_self_t* self = (_display_self_t*)_lf_new_reactor(sizeof(_display_self_t));
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
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
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
