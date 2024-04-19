#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/vm_extra/Input.h"
#include "_input.h"
// *********** From the preamble, verbatim:
#line 18 "/Users/sailor/Developer/git/EDAN15/Lab2/vm_extra.lf"
void clearInputBuffer()
{   char c = 0;
    do {
        c = getchar(); 
    } while (c != '\n' && c != EOF);
}
char getInput()
{   char c = 0;
    do {
        putchar('>');
        c = getchar(); 
    } while (c == '\n');
    return c;
}
void* external(void* a) {
    while (true) {
        clearInputBuffer();
        char c = getInput();
        lf_schedule_int(a, 0, c);
    }
}
#line 29 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/lab_2/_input.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _inputreaction_function_0(void* instance_args) {
    _input_self_t* self = (_input_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _input_a_t* a = &self->_lf_a;
    #line 48 "/Users/sailor/Developer/git/EDAN15/Lab2/vm_extra.lf"
    // Start a thread to schedule physical actions.
    lf_thread_create(&self->thread_id, &external, a);
#line 41 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/lab_2/_input.c"
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _inputreaction_function_1(void* instance_args) {
    _input_self_t* self = (_input_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _input_a_t* a = &self->_lf_a;
    // Set the fields of the action struct to match the current trigger.
    a->is_present = (bool)self->_lf__a.status;
    a->has_value = ((self->_lf__a.tmplt.token) != NULL && (self->_lf__a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)a, (self->_lf__a.tmplt.token));
    if (a->has_value) {
        a->value = *(int*)(self->_lf__a.tmplt.token)->value;
    }
    lf_critical_section_exit(self->base.environment);
    _input_cancel_t* cancel = &self->_lf_cancel;
    _input_sel_t* sel = &self->_lf_sel;
    _input_coin_t* coin = &self->_lf_coin;
    #line 53 "/Users/sailor/Developer/git/EDAN15/Lab2/vm_extra.lf"
    char c = a->value;
    switch(c) {
        case 'c': // insert coin
            lf_set(coin, true);
            break;
        case 'x': // cancel
            lf_set(cancel, true);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
            lf_set(sel, c-'0');
            break;
        default:
            break;
    }
#line 79 "/Users/sailor/Developer/git/EDAN15/src-gen/Lab2/lab_2/_input.c"
}
#include "include/api/set_undef.h"
_input_self_t* new__input() {
    _input_self_t* self = (_input_self_t*)_lf_new_reactor(sizeof(_input_self_t));
    self->_lf_a._base.trigger = &self->_lf__a;
    self->_lf_a.parent = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _inputreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _inputreaction_function_1;
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
    self->_lf__a.is_physical = true;
    
    self->_lf__a.tmplt.type.element_size = sizeof(int);
    self->_lf_a.type.element_size = sizeof(int);
    return self;
}
