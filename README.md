# TheoryOfAlgorithms
# SHA256
## Author: Kieran O'Halloran

## Student ID: G00326425

This is a program i compiled to run the SHA256 algorithm. This is for my 4th year Theory of Algorithms module in GMIT.


## Project Description
You must write a program in the C programming language that calculates
the SHA-256 checksum of an input. The algorithm is specified in the Secure
Hash Standard document supplied by the (United States) National Institute
of Standards and Technology. The only pre-requisite is that your program
performs the algorithm — you are free to decide what input the algorithm
should be performed on.

## How to run the program
1.1 To run the project, "git clone https://github.com/123kieran/SHA256"

1.2 You can simply navigate to the project.
    "cd SHA256"

1.3 Ensure GCC compiler is installed on the computer.
    Run the command "gcc -o sha256 sha256.c" in command prompt within the folder. 

1.4 Choose the file which you wish to Hash
    "./sha256 sha256"
    In this example I have chosen the program to hash itself.
    
## Additional Features
* Error handling is added to the program. Before opening the file. The program to see if the file is empty and if it is it gives an error message
* Changing to Big endian. The output is checked if in big/little endian. If in little endian, it is changed to big endian as required in sha256 algorithm document    

## Resources
* [How Does SHA256 Work?](https://www.youtube.com/watch?v=mbekM2ErHfM)

* [How secure is 256 bit security?](https://www.youtube.com/watch?v=mbekM2ErHfM)

* [US Government SHA256 Standard](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)

* [Little Endian vs Big Endian](https://www.geeksforgeeks.org/little-and-big-endian-mystery/)

* [Converting Little to Big Endian and Vice Versaa](https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian)

* [Testing with Hash calculator](https://www.xorbin.com/tools/sha256-hash-calculator)


