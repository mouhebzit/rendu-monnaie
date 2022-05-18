#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int8_t rendu_monnaie(uint8_t n, uint8_t s, int8_t **tabV, uint8_t *L, uint8_t **T );

int main(int argc, char const *argv[])
{
   uint8_t n = argc-2;
   uint8_t s=atoi(argv[argc-1]);
   
   int8_t **tabV = (int8_t**)malloc((n+1)*sizeof(int8_t*));
   uint8_t **T = (uint8_t**)malloc((n+1)*sizeof(uint8_t*));
   if (tabV == NULL)
   {
   	 printf("Erreur d'allocation memoire 1d.\n");
   	 return EXIT_FAILURE;
   }

   for (int8_t i = 0; i < (n+1); ++i)
   {
   	 tabV[i] = (int8_t*)malloc((s+1)*sizeof(int8_t));
   	 T[i] = (uint8_t*)malloc((s+1)*sizeof(uint8_t));
   	 if (tabV[i] == NULL)
   	 {
   	 	printf("Erreur d'allocation memoire 2d.\n ");
   	 	return EXIT_FAILURE;
   	 }
   }

    for (int8_t i = 0; i < (n+1); i++)
   {
   	for (int8_t j = 0; j < (s+1); j++)
   	{
   		tabV[i][j] = -10;
   		T[i][j] = 0;
   		//printf("%d",tabV[i][j]);
   	}
   }
   
   
   uint8_t *L = (uint8_t*)malloc((n+1)*sizeof(uint8_t));
   //uint8_t *T = (uint8_t*)malloc(5*sizeof(uint8_t));
   L[0]=0;
   for(uint8_t i =1; i<(n+1); i++){
   L[i]=atoi(argv[i]); 
   }
  
   
  /* T[0]=0;
   T[1]=0;
   T[2]=0;
   T[3]=0;
   T[4]=0;*/
   
   int8_t r = rendu_monnaie(n, s, tabV, L,T);
   printf("Le nombre minimal de pieces pour rendre %d est %d\n",s,r);
   
   
  
 return EXIT_SUCCESS;
}


int8_t rendu_monnaie(uint8_t n, uint8_t s, int8_t **tabV, uint8_t *L, uint8_t **T){
  int8_t a1,a2,m,m2,ii;
  int8_t min1=0;
  int8_t min2=0;

  if (tabV[n][s]>-1)
  {
  	return tabV[n][s];
  }
  else 
  {
    	if (s==0 || n==1)
     	{
     	  if (n==1 && L[n]>s && s>0)
     	  {
     	  	tabV[n][s] = 100;
     	  }
     	  else if (n==1 && L[n]<=s)
     	  {
     	  	if(s%L[n]==0)
     	  	  tabV[n][s] = s/L[n];
     	  	else
     	  		tabV[n][s] = 100;
     	  }
     	  else
  		  tabV[n][s]=0;
     
         return tabV[n][s];
     	}
    	else
    	{
    	   a1 = rendu_monnaie(n-1,s,tabV,L,T);
    	   min2=110;
    	   for (int8_t k = 0; k < s; k++)
    	   {
    	   	 for (uint8_t i = 1; i <= n; i++)
    	   	 {  
    	   	 	a2=100;
    	   	 	m=0;
    	   	   	if (((s-k)%L[i])==0)
    	   	        {
    	   	 	  m = (s-k)/L[i];
    	   	 	  a2 = rendu_monnaie(n-1,k,tabV,L,T)+m;
    	   	 	  
    	    	        }

    	    	if(a2<min2){
    	    	  min2=a2;
    	    	  m2=m; 
    	    	  ii=i;
                }
                
    	   	 
    	     }
    	  }
    	  if (a1<min2)
    	  {
    	  	min1=a1;
    	  	T[n][s]=0;
   	  	
    	  }
    	  else
    	         {
    	  	 min1 = min2;
    	  	 T[n][s]=m2;
    	  	}
             
    	  tabV[n][s] = min1;
          return tabV[n][s];


        }

    }

}



