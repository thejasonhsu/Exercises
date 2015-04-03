#include <iostream>

using namespace std;

int main()
{
  int init[3];    /* Initial number of quarters */
  int person[3];  /* Current number of quarters for each person */
  double p;       /* Fairness of the coin (probability of the coin flip) */
  double r;       /* Value to be used for random probability between 0 and 1 */
  double totalflips;   /* Total flips over all runs */

  /*====================================================*/
  /*  Declare other variables here                      */
  /*====================================================*/

  int sequenceflips;
  int flip[3];
  int flip_sum;
  int i, sequences;
  
  totalflips = 0;

  /*====================================================*/
  /* Seed the random number generator                   */
  /*====================================================*/
   printf("RAND_MAX is %u\n", RAND_MAX); 
  
  //cout << "RAND_MAX is" << RAND_MAX << endl;
  srand(1000);

  /*====================================================*/
  /* I/O for requesting initial values and fairness of  */
  /*   the coin init array and p should be initialized  */
  /*   here by the user                                 */
  /*====================================================*/
  
  //cout << "Enter the initial number of coins for reach person seperated by spaces: " << endl;
  //cin >> init [0] >> init[1] >> init[2];
  printf("Enter the initial number of coins for reach person seperated by spaces: ");
  scanf("%i %i %i", &init[0], &init[1], &init[2]);
  
  //cout << "Enter the probability (p) of the coin flips: " << endl;
  //cin >> p;
  printf("Enter the probability (p) of the coin flips: ");
  scanf("%lf", &p);
  
  /*====================================================*/
  /* Monte Carlo simulation                             */
  /*  Should loop 100,000 times                         */
  /*  At this point you should be able to use the       */
  /*  same algorithm that your Matlab code did          */
  /*====================================================*/
  
  for(sequences=0; sequences < 100000; sequences++)
	{
	sequenceflips = 0;
	person[0] = init[0];
	person[1] = init[1];
	person[2] = init[2];
	while(person[0] > 0 && person[1] > 0 && person[2] > 0)
		{
		for(i = 0; i<3; i++)
			{
			r = ((double)rand()/((double)RAND_MAX + (double)1));
			if(r<p)
				flip[i] = 0;
			else
				flip[i] = 1;
			}
			flip_sum = flip[0] + flip[1] + flip[2];
			if(flip_sum == 1 || flip_sum == 2)
				{
				if(flip_sum == 1)
					{
					for(i = 0; i<3; i++)
						{
						if(flip[i] == 0)
							flip[i] = -1;
						else
							flip[i] = 2;
						}
					}
				else
					{
					for(i=0;i<3;i++)
						{
						if(flip[i] == 0)
							flip[i] = 2;
						else
							flip[i] = -1;
						}
					}
				for(i=0;i<3;i++)
					{
					person[i] = person[i] + flip[i];
					}
				}
			sequenceflips = sequenceflips + 1;
			}
		totalflips = totalflips + sequenceflips;
	}
	
  
  /*====================================================*/
  /* Calculate the total flips and print out that value */
  /*  This code is complete and should not need to be   */
  /*  modified.                                         */
  /*====================================================*/
  
  totalflips = totalflips / 100000;
  //cout << "Average flips for 100,000 runs: " << totalflips << endl;
  printf("Average flips for 100,000 runs: %f\n",totalflips);
}
