/*
 PROBLEM STATEMENT
 Magic binary dot card
  Bernadette is a magical girl. She has a set of 64 cards: for each x between 0 and 63, she has a card that is blank on one side and has 2x dots on the other side.
 First 5 cards:
 Bernadette's cards are placed on a table. At any moment, the cards show some integer between 0 and (264)-1, inclusive. To read the number, Bernadette just counts all the dots using her magic power. For example, the number shown in above picture is 1 + 2 + 4 + 8 + 16 = 31.
 Bernadette is using the cards to count from A to B. That is, she is flipping some of the cards in such a way that the numbers A, A+1, ..., B appear in this order.
 Of course, Bernadette is using the shortest possible sequence of flips. Additionally, she always flips the cards one at a time. Sometimes, changing the number from some Z to Z+1 requires Bernadette to flip more than one card. In that case, she flips the necessary cards ordered by the number of dots they have, starting with the one with the most dots.
 For example, if A=6 and B=8, the following will happen:
  In the beginning, the card with 4 dots and the card with 2 dots are showing the dots, all other cards are blank side up. This shows the number 6.
  Bernadette flips the card with 1 dot. Now the number 7 is shown.
  Bernadette flips the card with 8 dots.
  Bernadette flips the card with 4 dots.
  Bernadette flips the card with 2 dots.
  Bernadette flips the card with 1 dot. Now the number 8 is shown and Bernadette is done.
 Given are A and B. Find the largest number that will be shown at any moment during Bernadette's counting.
  
 INPUT
 There are multiple inputs.
 There are two integers, A (1<=N<= 10^18), and B (A<=N<= 10^18), separated by a space.
 The input ends with EOF
 OUPUT
 For each test case, print the largest number that will be shown at any moment during Bernadette's counting.
 SAMPLE INPUT AND OUTPUT
 Input Ouput
 Hints:
 The third case is the example from the problem statement. When flipping cards to create the number 8 from the number 7, Bernadette starts by flipping the card with 8 dots. At this moment, the number shown on the cards is 15.
    66
 67
 68
 1 11
 35 38
 1125899906842630 1125899906842632
      6
 7
 15
 15
 39
 1125899906842639
       
 */

#include <stdio.h>
#include <math.h>

using ll = long long int;

ll answer(ll num1, ll num2)
{
    ll cnt = 0;
    
    ll ch1 = 1, ch2 = 2;
    while(true)
    {
        if(num2 >= ch1 && num2 < ch2 && num1 < ch1)
        {
            cnt = ch2-1;
            break;
        }
        else if(num2 >= ch1 && num2 < ch2 && num1 >= ch1 && num1 < ch2)
        {
            cnt = answer(num1 - ch1, num2 - ch1) + ch1;
            break;
        }
        ch1 = ch1 << 1;
        ch2 = ch2 << 1;
        
    }
    return cnt;
}

int main()
{
    ll num1, num2;
    while(scanf("%lld %lld", &num1, &num2)!=EOF)
    {
        if(num1 == num2)
        {
            printf("%lld\n", num1);
            continue;
        }
        printf("%lld\n", answer(num1, num2));
        
    }
    return 0;
}
