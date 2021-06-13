/*
 A chain of connected cells of two types A and B composes a cellular structure of some microorganisms of species APUDOTDLS.
 If no mutation had happened during growth of an organism, its cellular chain would take one of the following forms:
 simple stage
 fully-grown stage
 mutagenic stage
 O = A
 O = OAB
 O = BOA
 Sample notation O = OA means that if we added to chain of a healthy organism a cell A from the right hand side, we would end up also with a chain of a healthy
 organism. It would grow by one cell A.
 A laboratory researches a cluster of these organisms. Your task is to write a program which could find out a current stage of growth and health of an organism,
 given its cellular chain sequence.
 Input
 A integer n being a number of cellular chains to test, and then n consecutive lines containing chains of tested organisms.
 Output
 For each tested chain give (in separate lines) proper answers:
 organisms)
 SIMPLE
 FULLY-GROWN
 MUTAGENIC
 MUTANT
 for simple stage
 for fully-grown stage
 for mutagenic stage
 any other (in case of mutated
 If an organism were in two stages of growth at the same time the first option from the list above should be given as an answer.
 Sample Input
 4
 A
 AAB
 BAAB
 BAABA
 Sample Output
 SIMPLE
 FULLY-GROWN
 MUTANT
 MUTAGENIC
 */

#include <stdio.h>
#include <string.h>

int recursion(char* strain, int begin, int end)
{
    if(end-begin == 1 && strain[begin] == 'A')
        return 0;
    else if(strain[end-1] == 'B' && strain[end-2] == 'A')
    {
        if(recursion(strain, begin, end-2) != 3)
            return 1;
    }
    else if(strain[begin] == 'B' && strain[end-1] == 'A')
    {
        if(recursion(strain, begin+1, end-1) != 3)
            return 2;
    }
    return 3;
}

int main()
{
    int cases;
    char strain[1000];
    scanf("%d", &cases);
    char output[4][12] = {"SIMPLE", "FULLY-GROWN", "MUTAGENIC", "MUTANT"};
    while(cases--)
    {
        scanf("%s", strain);
        int leng = int(strlen(strain));
        printf("%s\n", output[recursion(strain, 0, leng)]);
    }
    return 0;
}
