#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "common.h"


int main() {
  Chunk chunk;
  
  initChunk(&chunk);
  
  for (double i = 0; i<300; i+=1.0) writeConstant(&chunk, i, (int)i);
  
  writeChunk(&chunk, OP_RETURN, 123);
  
  disassembleChunk(&chunk, "test chunk");
  
  freeChunk(&chunk);
    
  return 0;
}