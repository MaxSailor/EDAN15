#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Vending_Machine/Vending_Machine.h"
#include "_vending_machine_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_vending_machine_main_main_self_t* new__vending_machine_main() {
    _vending_machine_main_main_self_t* self = (_vending_machine_main_main_self_t*)_lf_new_reactor(sizeof(_vending_machine_main_main_self_t));

    return self;
}
