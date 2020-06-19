/*
    ->This is my first time implementation of FSM so this might be worst case implementation.
    ->The DFA of counting a variable value up and down is written below:

      Description of DFA
      1. set of all state      = {START, STATE_1, STATE_12, STATE_123, STATE_7, STATE_78, STATE_789} | total = 7
      2. set of inputs         = {-1, 1, 2, 3, 7, 8, 9}                                              | total = 7
      3. set of output state   = {STATE_123, STATE_789}                                              | total = 2
      4. initial state         = START

      LOGIC:
      case 1: when input sequence "123" is detected variable value is incremented.
      case 2: when input sequence "789" is detected variable value is decremented.
      case 3: when input sequence is other than above two case, depends on input the state transition occurs.
*/

#include <stdio.h>

typedef enum{
    START = 0,
    STATE_1,
    STATE_12,
    STATE_123,
    STATE_7 = 7,
    STATE_78,
    STATE_789
}State_et;

State_et Startfun(int option)
{
    State_et next_state;
    if(option == STATE_1) next_state = STATE_1;
    else if(option == STATE_7) next_state = STATE_7;
    else next_state = START;
    return next_state;
}

State_et State1fun(int option)
{
    State_et next_state;
    if(option == STATE_1) next_state = STATE_1;
    else if(option == STATE_12) next_state = STATE_12;
    else if(option == STATE_7) next_state = STATE_7;
    else next_state = START;
    return next_state;
}

State_et State12fun(int option)
{
    State_et next_state;
    if(option == STATE_1) next_state = STATE_1;
    else if(option == STATE_123) next_state = STATE_123;
    else if(option == STATE_7) next_state = STATE_7;
    else next_state = START;
    return next_state;
}

State_et State123fun(int option)
{
    State_et next_state;
    if(option == STATE_1) next_state = STATE_1;
    else if(option == STATE_7) next_state = STATE_7;
    else next_state = START;
    return next_state;
}

State_et State7fun(int option)
{
    State_et next_state;
    if(option == STATE_7) next_state = STATE_7;
    else if(option == STATE_78) next_state = STATE_78;
    else if(option == STATE_1) next_state = STATE_1;
    else next_state = START;
    return next_state;
}

State_et State78fun(int option)
{
    State_et next_state;
    if(option == STATE_7) next_state = STATE_7;
    else if(option == STATE_789) next_state = STATE_789;
    else if(option == STATE_1) next_state = STATE_1;
    else next_state = START;
    return next_state;
}

State_et State789fun(int option)
{
    State_et next_state;
    if(option == STATE_7) next_state = STATE_7;
    else if(option == STATE_1) next_state = STATE_1;
    else next_state = START;
    return next_state;
}

void main()
{
    State_et cur_state = START;
    unsigned int count = 0;
    int option;
    while(1)
    {
        switch(cur_state)
        {
        case START:
            {
                printf("I am in START :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = Startfun(option);
                break;
            }
        case STATE_1:
            {
                printf("I am in STATE_1 :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State1fun(option);
                break;
            }
        case STATE_12:
            {
                printf("I am in STATE_12 :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State12fun(option);
                break;
            }
        case STATE_123:
            {
                printf("I am in STATE_123 :");
                ++count;
                printf("Incremented\nnext data:");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State123fun(option);
                break;
            }
        case STATE_7:
            {
                printf("I am in STATE_7 :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State7fun(option);
                break;
            }
        case STATE_78:
            {
                printf("I am in STATE_78 :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State78fun(option);
                break;
            }
        case STATE_789:
            {
                printf("I am in STATE_789 :");
                --count;
                printf("Decremented\nnext data :");
                scanf("%d",&option);
                if(option == -1) goto exit;
                cur_state = State789fun(option);
                break;
            }
        }
    }
    exit:
    printf("\nFinal value of count : %d", count);
}
