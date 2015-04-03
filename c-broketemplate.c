#include <stdio.h>
#include <stdlib.h>

int main()
{
  int initM[3];    /* Initial number of quarters */
  int Man[3];  /* Current number of quarters for each person */
  double p;       /* Fairness of the coin (probability of the coin flip) */
  double r;       /* Value to be used for random probability between 0 and 1 */
  double totalflips;   /* Total flips over all runs */

  /*====================================================*/
  /*  Declare other variables here                      */
  /*====================================================*/
 


  /*====================================================*/
  /* Seed the random number generator                   */
  /*====================================================*/
  /*  printf("RAND_MAX is %u\n", RAND_MAX); */
  srand(1000);

  /*====================================================*/
  /* I/O for requesting initial values and fairness of  */
  /*   the coin init array and p should be initialized  */
  /*   here by the user                                 */
  /*====================================================*/


  /*====================================================*/
  /* Monte Carlo simulation                             */
  /*  Should loop 100,000 times                         */
  /*  At this point you should be able to use the       */
  /*  same algorithm that your Matlab code did          */
  /*====================================================*/





  /*====================================================*/
  /* Calculate the total flips and print out that value */
  /*  This code is complete and should not need to be   */
  /*  modified.                                         */
  /*====================================================*/
  totalflips = totalflips / 100000;
  printf("Average flips for 100,000 runs: %6.3lf\n", totalflips);
}
