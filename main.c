#include <wiringPi.h> //this library SHOULD be pre-installed with
                      //with standard Rasbian system.
                      //If it seems missing on your Raspberry, then
                      //I recommend following the steps provided here:
                      //http://wiringpi.com/download-and-install/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define	LED	17 //that means, that program will work with GPIO 17, which
               //is number 11 on rpi GPIO pinout.
#define RAND_MAX 1000 //it's a max value that rand function can return

int main(void)
{
    wiringPiSetupSys();

    srand(time(0));

    pinMode(LED, OUTPUT);

    int count = 0; //counter
    int rand_H; //the highest random value
    int rand_L; //the lowest random value
    const int iter = 10; //number of iterations
    while (count < iter)
    {
        rand_H = rand() % RAND_MAX + 5;
        digitalWrite(LED, HIGH);
        delay(rand_H);
        printf("Delay (HIGH): %d ms.\n", rand_H);
        rand_L = rand() % RAND_MAX + 100;
        digitalWrite(LED, LOW);
        delay(rand_L);
        printf("Delay (LOW): %d ms.\n", rand_L);
        printf("Iteration: %d.\n", count);
        count++;
    }

    return 0;
}

