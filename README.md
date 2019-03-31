# SHA256


This application is an interpretation of the sha256 algorithm. It is based on the sha256 description provided by the United states government. This algorithm is used as the bases of bitcoins and many other services. This algorithm is relatively easy to make a hash from however it is very difficult to decrypt the algorithm.

## Compile
* git clone https://github.com/123kieran/SHA256
* cd SHA256
* In order to compile this program, GCC compiler must be installed on the computer.
* Run the command "gcc -o sha256 sha256.c" in command prompt within the folder.


## Run
* To run the application, a file must be chosen to hash, run "./sha256 sha256". 
* Here I have chosen the program to hash itself.

## Test
* I used the following like to test my output. https://www.xorbin.com/tools/sha256-hash-calculator

## Additional Features
* Error handling is added to the program. Before opening the file. The program to see if the file is empty and if it is it gives an error message
* Changing to Big endian. The output is checked if in big/little endian. If in little endian, it is changed to big endian as required in sha256 algorithm document

