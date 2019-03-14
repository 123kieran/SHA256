// Author: Kieran O'Halloran
// The Secure Hash Algorithm, 256 bit Version

 #include <stdio.h>
 #include <stdint.h>

 void sha256();

 //see section 4.1.2
 int32_t sig0(uint32_t x);
 uint32_t sig1(uint32_t x);

 //see section 3.2.1
 uint32_t rotr(uint32_t n, uint32_t x);
 uint32_t shr(uint32_t n, uint32_t x);

 //See Section 4.1.2
 uint32_t SIG0(uint32_t x);
 uint32_t SIG1(uint32_t x);

 //see section 4.1.2
 uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);
 uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);

 int main(int argc, char *argv[]){

   sha256();

     return 0;
     }

  void sha256(){
       
      //Message Schedule
      unit32_t W[64]
      //Working variables;
                 
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
       x1f83d9ab,
         0x5be0cd19
 	};


  //the  current message block
    uint32_t M[16];
      
  // for looping 
     int t;
  
       for(t =0; t <  16; t++)
           W[t] = M[t];
  
         for(t = 16; t <64; t++)
             sig1(W[t-2]) + W[t-7] + sig0(W[t-15]) + W[t-16];
	     //initialise a ,b, c. d, e, f, g, h.
	      a = H[0]; b = H[1]; c = H[2]; d = H[3]; e = H[4];
	      f = H[5], g = H[6], h = H[7];
	     
	     //Step 3
	      for (t = 0; t < 64; t++){
	       T1 = h + SIG1(e) + Ch(e, f, g) + K[t] + W[t];
	       T2 = SIG0(a) + Maj(a, b, c);
	       h = g;
	       g = f;
               f = e;
               e = d + T1;
               d = c;
               c = b;
               b = a;
               a = T1 + T2;
     
           }
    
	     
           //Step 4.
              H[0] = a + H[0];
              H[1] = b + H[1];
              H[2] = c + H[2];
              H[3] = d + H[3];
              H[4] = e + H[4];
              H[5] = f + H[5];
              H[6] = g + H[6];
              H[7] = h + H[7];
     
	     
           }
  
       uint32_t rotr(uint32_t n, uint32_t x){
           return (x >> n) | (x << (32 -n));
       }
      uint32_t shr(uint32_t n, uint32_t x){
                return(x >> n);
	     
	       }
	     
     uint32_t sig0(uint32_t x){
     return(rotr(7, x) ^ rotr(18, x) ^ shr(3, x));
                                                                                                                                        
               }
    uint32_t sig1(uint32_t x){
      return(rotr(17, x) ^ rotr(19, x) ^ shr(10, x));



     //See Section 4.1.2
    uint32_t SIG0(uint32_t x){
     return (rotr(2, x) ^ rotr(13, x) ^ rotr(22, x));

 }
    uint32_t SIG1(uint32_t x){
     return (rotr(6, x) ^ rotr(11, x) ^ rotr(25, x));

   }

   uint32_t Ch(uint32_t x, uint32_t y, uint32_t z){
     return((x & y) ^ ((!x) & z));

       }
   uint32_t Maj(uint32_t x, uint32_t y, uint32_t z){
     return((x & y) ^ (x & z) ^ (y & z));
         

	    
  }
