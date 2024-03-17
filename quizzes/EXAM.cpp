

#include <iostream>
#include <vector>

const int ERROR_IN_VECTOR_SIZE = -1000000; /*can be any number the user will choose to use*/


int solution(std::vector<int> &A, std::vector<std::string> &D) 
{
    int payment_sum[13] = {0};
    int payment_amount[13] = {0};
    size_t counter = 0;
    size_t fee_on_card = 12;

    int sum = 0;

    if(A.size() != D.size())
    {
        return ERROR_IN_VECTOR_SIZE;
    }

    for(auto iter : D)
    {
        
        if(iter[5] == '0' && iter[6] == '1')
        {
            if(A[counter] < 0)
            {
                payment_sum[1] += A[counter];
                ++payment_amount[1];
            }
        }
        if(iter[5] == '0' && iter[6] == '2')
        {
            if(A[counter] < 0)
            {
                payment_sum[2] += A[counter];
                ++payment_amount[2];
            }
        }
        if(iter[5] == '0' && iter[6] == '3')
        {
            if(A[counter] < 0)
            {
                payment_sum[3] += A[counter];
                ++payment_amount[3];
            }
        }
        if(iter[5] == '0' && iter[6] == '4')
        {
            if(A[counter] < 0)
            {
                payment_sum[4] += A[counter];
                ++payment_amount[4];
            }
        }
        if(iter[5] == '0' && iter[6] == '5')
        {
            if(A[counter] < 0)
            {
                payment_sum[5] += A[counter];
                ++payment_amount[5];
            }
        }
        if(iter[5] == '0' && iter[6] == '6')
        {
            if(A[counter] < 0)
            {
                payment_sum[6] += A[counter];
                ++payment_amount[6];
            }
        }
        if(iter[5] == '0' && iter[6] == '7')
        {
            if(A[counter] < 0)
            {
                payment_sum[7] += A[counter];
                ++payment_amount[7];
            }
        }
        if(iter[5] == '0' && iter[6] == '8')
        {
            if(A[counter] < 0)
            {
                payment_sum[8] += A[counter];
                ++payment_amount[8];
            }
        }
        if(iter[5] == '0' && iter[6] == '9')
        {
            if(A[counter] < 0)
            {
                payment_sum[9] += A[counter];
                ++payment_amount[9];
            }
        }
        if(iter[5] == '1' && iter[6] == '0')
        {
            if(A[counter] < 0)
            {
                payment_sum[10] += A[counter];
                ++payment_amount[10];
            }
        }
        if(iter[5] == '1' && iter[6] == '1')
        {
            if(A[counter] < 0)
            {
                payment_sum[11] += A[counter];
                ++payment_amount[11];
            }
        }
        if(iter[5] == '1' && iter[6] == '2')
        {
            if(A[counter] < 0)
            {
                payment_sum[12] += A[counter];
                ++payment_amount[12];
            }
        }
        sum += A[counter];
        ++counter;
    }
    
    for(size_t i = 1; i < 13; ++i)
    {
        if(payment_amount[i] >= 3 && payment_sum[i] * (-1) >= 100)
        {  
            --fee_on_card;
        }
    }

    return (sum - (5 * fee_on_card));
}

/* int solution(std::string &S) 
{
    int result = 0;

    size_t counter = 0;

    while(counter < S.size())
    {
        if(S[counter] == 'X')
        {
            counter += 3;
            ++result;
        }
        else
        {
            ++counter;
        }
    }
    return result;
} */

int main()
{
    std::vector<int> A = {180, -25, -25, -50};
    std::vector<std::string> D = {"2020-01-31", "2020-01-22", "2020-01-23", "2020-01-11"};

    int result = solution(A, D);
    std::cout<< "The result is " << result << std::endl;

    return 0;
}