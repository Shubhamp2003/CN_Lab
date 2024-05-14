/*Write a C Program to enter a number and store the number across the following
structure and print the content of each member of the structure. Then aggregate each
member of the structure to form the original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
*/

#include <stdio.h>
struct pkt{
    unsigned char ch1;
    unsigned char ch2[2];
    unsigned char ch3;
}pkt1;
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    pkt1.ch1 = num & 0xFF;
    pkt1.ch2[0] = (num >> 8) & 0xFF;
    pkt1.ch2[1] = (num >> 16) & 0xFF;
    pkt1.ch3 = (num >> 24) & 0xFF;

    printf("Byte 1: %d\n", pkt1.ch1);
    printf("Byte 2 and 3: %d , %d\n", pkt1.ch2[0],pkt1.ch2[1]);
    printf("Byte 4: %d\n", pkt1.ch3);

    //aggregate
    int num2 = pkt1.ch1 | pkt1.ch2[0] << 8 | pkt1.ch2[1] << 16 | pkt1.ch3 << 24;
    printf("Aggregated number: %d",num2);
    return 0;

}