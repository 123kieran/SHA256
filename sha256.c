// Author: Kieran O'Halloran
// The Secure Hash Algorithm, 256 bit Version

 #include <stdio.h>
 #include <stdint.h>
//Represents a message block
 union msgblock {
    uint8_t e[64];
    uint32_t t[16];
    uint64_t s[8];
};
//A flag for where we are in reading the file
 enum status {READ, PAD0, PAD1, FINISH};

 //see section 4.1.2
 uint32_t sig0(uint32_t x);
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

 //Calculates the SHA256 of a file
 void sha256(File *f);

//Retrives the next message block
 int nextmsgblock(FILE *f, union msgblock, enum status *S, int *nobites);

 //Starting everything
 int main(int argc, char *argv[]){

	 //ADD ERROR CHECKING
	 //Open the file given as command line argument
      FILE* f;
      f = fopen(argv[1], "r");
     
      //run the SHA on the file
      sha256(f); 

      //close the file
      fclose(f);

      return ;
     }

//sha256 function (return 256 message digest) array of 32 bit integers
  void sha256(){
	  //the current message block
       union msgblock M;

       //the number of bits read from the file
       uint64_t nobits=0;
      

       //the status of the message blocks, in terms of padding	        
       enum status S = READ;

      //The K Constants. Defined in Section 4.2.2
          uint32_t K[]={
            0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
            0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
            0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 
            0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
            0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
	    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
	    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
	    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
	    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
	    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
	    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
	    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
	    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
	    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
	    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
	    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 
	  };
	  
	  //Message Schedule
     uint32_t W[64];
      //Working variables;
       uint32_t a,b,c,d,e,f,g,h;
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


  //the  current message block
    uint32_t M[16] = {0,0,0,0,0,0,0,0};
      
  // for looping 
     int i,t;

     //loop through message blocks as per page 22
     while (nextmsgblock(f, M, S, nobits)){

  
       for(t =0; t <  16; t++)
           W[t] = M[t];
  
       for(t = 16; t <64; t++)
          W[t] = sig1(W[t-2]) + W[t-7] + sig0(W[t-15]) + W[t-16];
	     //initialise a ,b, c. d, e, f, g, h.
	      a = H[0]; b = H[1]; c = H[2]; d = H[3];
	      e = H[4]; f = H[5], g = H[6], h = H[7];
	     
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
     printf("%x, %x, %x, %x, %x, %x, %x, %x\n", H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]);
  }
  
 uint32_t rotr(uint32_t n, uint32_t x){
   return (x >> n) | (x << (32 -n));
  }

 uint32_t shr(uint32_t n, uint32_t x){
   return(x >> n);
  }

 uint32_t sig0(uint32_t x){
   return(rotr(7, x) ^ rotr(18, x) ^ shr(3, x));                                   }

 uint32_t sig1(uint32_t x){
   return(rotr(17, x) ^ rotr(19, x) ^ shr(10, x));
  }
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
   
int nextmsgblock(FILE *f, union msgblock *M, enum status *S, int *nobits){
    //The number of bytes to get from fread
     uint64_t nobytes;
	
	//For looping
     int i;
	//if we have finished all the message blosks, then S should be 0
     if(*S == FINISH)
        return 0;

	//otherwise check if we need another block of padding
	if( *S == PAD0|| *S == PAD1){
		//set the first 56 bytes to all zero bits
	for(int i = 0;i<56;i++)		
	   M->e[i] = 0x00;
	//set the last 64 bits to the number in the file (Should be big endian)	 
  	   M->s[7] = *nobits;
	   //tell S were finished
	  *S= FINISH;
	
	//if S was PAD1, then set the first bit of M to one.
	if(S == PAD1)							
	M.e[0] = 0x80;
	//keep the look going for one more iteration
	return 1;
	}


//if we get here we havent finished reading the (file S==READ)

     
     nobytes = fread(M->e,1,64,f);
    	//keep track of number of bytes read
     *nobits = *nobits + (nobytes * 8);
     //if we read less than 56 bytes, we can put all padding in this message block
      if (nobytes < 56) {
     //add the one bit, as per the standard
      M->e[nobytes] = 0x80;
     //Add xero bits until the last 64 bits
      while (nobytes < 56) {	
      nobytes = nobytes + 1;
      M->e[nobytes] = 0x00;
     }							     
     //Append the file size in bits as a unsigned 64 bit int
      M.s[7] = nobits;
      //tell S were finished
      *S = FINISH;
      //otherwise, check can we put some padding into this message block
      }else if(nobytes <64){
      //Tell S we neex anothe message block, whit padding but no one bit
      *S=PAD0;
      //put the one bit into the current block
      M->e[nobytes]=0x80;
      //Pad the rest of the block with zero bits
      while(nobytes<64){	 		    		                 
      nobytes = nobytes +1;	
      M.e[nobytes] = 0x00;
     }                	  									//Otherwise, check if were just at the end of the file
    } else if(feof(f)){	
	//tell S that we need another message block with all the padding	    
      *S = PAD1;		
     }
    
												      
	 
   
	//if we get this far, then return 1 so this function is called again
	return 1;
    }
