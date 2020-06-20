/*
    ->The Mealy Machine of generating 2s complement is written below:
    ->Input formate is LSB first MSB last.

      Description of Mealy Machine:
      1. set of all state      = {START, S1}     | total = 2
      2. set of inputs         = {-1, 1, 0}      | total = 3
      3. set of output         = {0, 1}          | total = 2
      4. initial state         = START

*/

#include <stdio.h>

typedef enum
{
    LOGIC_0,
    LOGIC_1
}Logic_et;

typedef enum
{
    START,
    S1
}State_et;

State_et fun_start(char data)
{
    State_et next_state;
    if(data == LOGIC_1)
    {
        printf("(1)\n");
        next_state = S1;
    }
    else
    {
        printf("(0)\n");
        next_state = START;
    }
    return next_state;
}

State_et fun_s1(char data)
{
    State_et next_state = S1;
    data = !data;
    printf("(%d)\n",data);
    return next_state;
}

void main()
{
    char data;
    State_et cur_state = START;
    while(1)
    {
        switch(cur_state)
        {
        case LOGIC_0:
            {
                printf("I am in START :");
                scanf("%d",&data);
                if(data == -1){goto exit;}
                cur_state = fun_start(data);
                break;
            }
        case LOGIC_1:
            {
                printf("I am in LOGIC_1 :");
                scanf("%d",&data);
                if(data == -1){goto exit;}
                cur_state = fun_s1(data);
                break;
            }
        }
    }
    exit:
    printf("Terminated!");
}
