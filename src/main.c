#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "common.h"


int main() {
  Chunk chunk;
  
  initChunk(&chunk);
  
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constant);
  
  disassembleChunk(&chunk, "test chunk");
  
  freeChunk(&chunk);
    
  return 0;
}