#include <signal.h>
#include <stddef.h>
#include <stdio.h>  // getchar
#include <stdlib.h> // exit
#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>

// Pour compiler ce fichier et le linker avec les fonctions assembleur:
// $ gcc -static -Wall tp3-skeleton.c tp3-skeleton.s -o tp3

// Vous pouvez ensuite lancer le programme compilÃ©:
// $ ./tp3

// The size of our stacks
#define STACK_SIZE_FULL 4096

typedef void *coroutine_t;

unsigned char ptr[4][STACK_SIZE_FULL];


/* Quitte le contexte courant et charge les registres et la pile de CR. */
void enter_coroutine(coroutine_t cr);


/* Sauvegarde le contexte courant dans p_from, et entre dans TO. */
void switch_coroutine(coroutine_t *p_from, coroutine_t to);



/* Initialise la pile et renvoie une coroutine telle que, lorsquâ€™on entrera
dedans, elle commencera Ã  sâ€™exÃ©cuter Ã  lâ€™adresse initial_pc. */
coroutine_t init_coroutine(void *stack_begin, size_t stack_size,
                           void (*initial_pc)(void))
{
        printf("%p\n", initial_pc);
        char *stack_end = ((char *)stack_begin) + stack_size;
        void **ptr = (void **)stack_end;
        ptr--;
        *ptr = initial_pc;
        ptr--;
        for(int i=0;i<5;i++){
            *ptr = 0;
            ptr--;
        }
        return ptr;
}

void infinito(){
    printf("ENTROU\n");
    int i = 0;
    while(1){
        printf("MENSAGEM[%d]\n", i);
        i++;
    }
}





int main() { 
    // coroutine_t cr1 = init_coroutine(ptr[0], STACK_SIZE_FULL, infinito);
    // enter_coroutine(cr1);
    infinito(0);
    return 0;
}