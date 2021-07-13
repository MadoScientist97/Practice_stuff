#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    if (argc==0){
        printf("No arguement was provided exiting.");
        exit(-1);
    }
    float number = atof(argv[1]);
    if (number<=0.0){
        printf("please Enter a valid arguement. Exiting");
        exit(-2);
    }
    long i;
    float x2,y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = y * (threehalfs - (x2* y * y ));
//  y = y * (threehalfs - (x2* y * y ));
    printf("%f\n" , y );
    return 0;
}
