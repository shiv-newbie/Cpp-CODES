#include <stdio.h>
#include <map>

int main()
{
    int num, hour, min, sec, var;
    
    while(true)
    {
        scanf("%d", &num);
        if(num == 0)                // cheking for 3 zeroes
            break;

        std::map<int, int>::iterator itr;
        std::map<int, int> check;
        
        int myMin = INT32_MAX;
        while(num)                  // Breaks when num == 0
        {
            myMin = std::min(myMin, num);
            check[num] = 1;
            scanf("%d", &num);
        }

        for(num = myMin - 5; num <= 60 * 60 * 5; num++)
        {
            for(itr = check.begin(); itr != check.end(); itr++)
            {
                var = (num / (2 * itr->first)) * (2 * itr->first);
                if(num >= (var + itr->first - 5))
                    break;
            }
            
            if(itr == check.end())
            {
                hour = num / 3600;
                num %= 3600;
                min = num / 60;
                sec = num % 60;
                
                printf("%02d:%02d:%02d\n", hour, min, sec);
                break;
            }
        }
        
        if(num > 60 * 60 * 5)
        {
            printf("Signals fail to synchronise in 5 hours\n");
        }
    }


    return 0;
}

