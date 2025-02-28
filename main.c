#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dbg/dbg.h>

// get read of suspicious format string
#pragma dontwarn 214

#pragma dontwarn 168
const char __ver[] = "$VER: Memory Dump 1.1 (16/02/2025)";
#pragma popwarn

int main(int argc, char *argv[])
{
    int32_t address;
    int32_t size;
    
    check(3 == argc, "Usage: dump <address> <size>\n\n");

    address = strtol(argv[1], NULL, 0);
    check(((LONG_MAX != address) && (LONG_MIN != address)), "error reading address value");
    if(0L == address)
    {
        fprintf(stderr, "got 0L as address, maybe an error ?\n");
    }
    
    size = strtol(argv[2], NULL, 0);
    check(((0L != size) && (LONG_MAX != size) && (LONG_MIN != size)), "error reading size value");
    
    printf("Address: %08lx  size: %ld\n", address, size);
    hexdump(address, size);
    return 0;
    
    
on_error:
   return 5; 
}
