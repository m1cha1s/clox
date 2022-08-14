#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "value.h"
#include "vm.h"
#include <stdio.h>

static InterpretResult run(); 

VM vm;

void initVM() {
	
}

void freeVM() {
	
}

InterpretResult interpret(Chunk* chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}

static InterpretResult run() {

#define READ_BYTE()          ((uint32_t)(*vm.ip++))
#define READ_CONSTANT()      (vm.chunk->constants.values[READ_BYTE()])
#define READ_CONSTANT_LONG() (vm.chunk->constants.values[READ_BYTE() | READ_BYTE() << 8 | READ_BYTE() << 16])
  
  for(;;) {
    
#ifdef DEBUG_TRACE_EXECUTION
    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif    
    
    uint8_t instruction;
    
    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT_LONG: {
        Value constant = READ_CONSTANT_LONG();
        printValue(constant);
        printf("\n");
        break;
      }
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();
        printValue(constant);
        printf("\n");
        break;
      }
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }
  
#undef READ_BYTE
#undef READ_CONSTANT
#undef READ_CONSTANT_LONG
}
