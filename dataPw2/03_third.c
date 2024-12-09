#include <stdio.h>
float toCelsius(float f){
    return (f-32)*(5.0 / 9.0);
}
int main(){
    float Celcius,Farenheit;
    printf("Enter the temperature in Farenheit: ");
    scanf("%f",&Farenheit);
    Celcius = toCelsius(Farenheit);
    printf("The temperature is %.2f\n",Celcius);
    return 0;
}