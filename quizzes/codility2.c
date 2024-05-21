

struct Results 
{
  int * A;
  int N; 
};

struct Results solution(int A[], int N, int K) 
{
    
    if(&A[0] == NULL || N == 0)
    {
        exit(1);
    }

    struct Results result;
    int *help_arr = (int *)malloc(sizeof(int) * N);

    if(help_arr == NULL)
    {
        result.A = NULL;
        result.N = 0;
        return result;
    }
    K %= N;
  
    for(int i = 0; i < N; ++i)
    {
        help_arr[(i + K) % N] = A[i];
    }

    for(int i = 0; i < N; ++i)
    {
        A[i] = help_arr[i];
    }

    free(help_arr);

    result.N = N;
    result.A = &A[0];
    return result;
}
