#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/helloworld/helloworld.h"
#include "_helloworld_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _helloworld_mainreaction_function_0(void* instance_args) {
    _helloworld_main_main_self_t* self = (_helloworld_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 5 "/Users/sailor/Developer/EDAN15/helloworld.lf"
    printf("Hello World.\n");
#line 14 "/Users/sailor/Developer/EDAN15/src-gen/helloworld/_helloworld_main.c"
}
#include "include/api/set_undef.h"
_helloworld_main_main_self_t* new__helloworld_main() {
    _helloworld_main_main_self_t* self = (_helloworld_main_main_self_t*)_lf_new_reactor(sizeof(_helloworld_main_main_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _helloworld_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
