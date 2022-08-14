#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "common.h"
#include "vm.h"


int main() {
  initVM();
  
  Chunk chunk;
  
  initChunk(&chunk);
  
  writeConstant(&chunk, 1567.8, 123);
  writeChunk(&chunk, OP_NEGATE, 123);
  writeChunk(&chunk, OP_RETURN, 123);
  
  printf("Interpreting\n");
  interpret(&chunk);
  
  freeChunk(&chunk);
  printf("Freeing VM\n");
  freeVM();

  return 0;
}