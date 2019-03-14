// Author: Kieran O'Halloran
// The Secure Hash Algorithm, 256 bit Version

 #include <stdio.h>
 #include <stdint.h>

 void sha256();

 int main(int argc, char *argv[]){

   sha256();

     return 0;
     }

  void sha256(){
       
      //Message Schedule
        uint32_t W[64];

      //Working variables
        uint32_t a, b, c, d, e, f, g;
                 
      //Temporary Variables
        uint32_t T1, T2;

      // The Hash value.
        uint32_t H[8] = {
         0x6a09e667,
         0xbb67ae85,
         0x3c6ef372,
         0xa54ff53a,   
         0x510e527f,
         0x9b05688c,
         0x1f83d9ab,
         0x5be0cd19
 	};

  } 
