#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/lab_2/Machine.h"
#include "_machine.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_machine_self_t* new__machine() {
    _machine_self_t* self = (_machine_self_t*)_lf_new_reactor(sizeof(_machine_self_t));
    // Set input by default to an always absent default input.
    self->_lf_cancel = &self->_lf_default__cancel;
    // Set the default source reactor pointer
    self->_lf_default__cancel._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_sel = &self->_lf_default__sel;
    // Set the default source reactor pointer
    self->_lf_default__sel._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_coin = &self->_lf_default__coin;
    // Set the default source reactor pointer
    self->_lf_default__coin._base.source_reactor = (self_base_t*)self;
    self->_lf__cancel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__cancel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__cancel.tmplt.type.element_size = sizeof(bool);
    self->_lf__sel.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__sel.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__sel.tmplt.type.element_size = sizeof(int);
    self->_lf__coin.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__coin.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__coin.tmplt.type.element_size = sizeof(bool);
    return self;
}
