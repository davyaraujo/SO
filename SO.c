#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct fs_header{
    char romfs[8];
    u_int32_t fullsize;
    u_int32_t checksum;
    char volumename[];
};


long ceil_16(long x) {
  // A COMPLETER - Question 5
  long y;
  y = x % 16;

  x = x + y;

  return x;
}

void decode(struct fs_header *p, size_t size){
    int i=0;
    for(i=0;i<=7;i++)
        printf("%c", p->romfs[i]);  
        puts("");

    printf("Fullsize: %u\n", p->fullsize);
    printf("Checksum: %u\n", p->checksum);
    printf("Volumename: %s\n", p->volumename);

 // Get the root file offset
  // A COMPLETER - Question 6
    uint32_t offset = ceil_16(strlen(p->volumename)+1);
    struct file_header *root = NULL;

}

uint32_t read32(char ptr[4]){

    u_int32_t a = ptr[0] << 24;
    u_int32_t b = ptr[1] << 16;
    u_int32_t c = ptr[2] << 8;
    u_int32_t d = ptr[3];
    
    u_int32_t mot = a|b|c|d;

    printf("%u", mot);

    return mot;
} 



int main(void){
    int fd = open("fs.romfs",O_RDONLY); 
    assert(fd != -1);
    off_t fsize;
    fsize = lseek(fd,0,SEEK_END);
    // printf("size is %d", fsize);
    struct fs_header *addr = mmap(addr, fsize, PROT_READ, MAP_SHARED, fd, 0);
    assert(addr != MAP_FAILED);
    decode(addr, fsize);
    return 0;
}