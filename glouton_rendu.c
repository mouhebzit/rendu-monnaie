#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int8_t rendu_monnaie(uint8_t n, uint8_t s, uint8_t *L, uint8_t *T );

int main(int argc, char const *argv[])
{
   uint8_t n = argc-2;
   uint8_t somme=atoi(argv[argc-1]);
   
   uint8_t *L = (uint8_t*)malloc(n*sizeof(uint8_t));
   uint8_t *T = (uint8_t*)malloc(n*sizeof(uint8_t));

   for(uint8_t i =0; i<n; i++){
   L[i]=atoi(argv[i+1]); 
   T[i]=0; 
   }
  

   int8_t r = rendu_monnaie(n, somme,L,T);
   printf("Le nombre minimal de pieces pour rendre %d est %d\n",somme,r);
    for (int8_t i = 0; i < n; i++)
   {
    printf("%d ",T[i]);
   		
   }
   	
  

  
 return EXIT_SUCCESS;
}


int8_t rendu_monnaie(uint8_t n, uint8_t s, uint8_t *L, uint8_t *T){
  uint8_t i=0;
  uint8_t rendu=0;
  uint8_t somme_pieces=0;
  
  while(s-rendu !=0){
     
     if(rendu + L[i] > s)
      i++;
     else {
        T[i]=T[i]+1;
        rendu = rendu + L[i]; 
        somme_pieces++;
     }
       
  }
  
  
 
  return somme_pieces;
  

}



