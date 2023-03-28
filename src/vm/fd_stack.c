#include "fd_stack.h"


fd_vm_stack_t *
fd_vm_stack_init( fd_vm_stack_t * stack ) {
  stack->stack_pointer = 0;
  stack->frames_used = 0;
  fd_memset(stack->frames, 0, sizeof(stack->frames));
  fd_memset(stack->data, 0, sizeof(stack->data));
}

ulong 
fd_vm_stack_push( fd_vm_stack_t * stack, ulong saved_regs[4] ) {
  if( stack->frames_used >= FD_VM_STACK_MAX_DEPTH ) {
    return FD_VM_STACK_OP_ERR_PUSH_OVERFLOW;
  }

  stack->frames_used++;
}

ulong fd_vm_stack_pop( fd_vm_stack_t * stack, ulong saved_regs[4] );