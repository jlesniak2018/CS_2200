#include <stdlib.h>

#include "types.h"
#include "pagetable.h"
#include "global.h"
#include "process.h"

/*******************************************************************************
 * Finds a free physical frame. If none are available, uses a clock sweep
 * algorithm to find a used frame for eviction.
 *
 * @return The physical frame number of a free (or evictable) frame.
 */


pfn_t get_free_frame(void) {
   int i;

   /* See if there are any free frames */
   for (i = 0; i < CPU_NUM_FRAMES; i++)
      if (rlt[i].pcb == NULL)
         return i;

   /* FIX ME : Problem 5 */
   /* IMPLEMENT A CLOCK SWEEP ALGORITHM HERE */
   /* Note: Think of what kinds of frames can you return before you decide
      to evict one of the pages using the clock sweep and return that frame */
   while (1) {
     int counter = 0;
     while (counter < CPU_NUM_FRAMES) {
       pte_t *victim_pagetable = rlt[counter].pcb->pagetable;
       if (victim_pagetable[rlt[counter].vpn].used == 0) {
         return counter;
       } else {
         victim_pagetable[rlt[counter].vpn].used = 0;
         counter++;
       }
     }
   }

   /* If all else fails, return a random frame */
   return rand() % CPU_NUM_FRAMES;
}
