#include <iostream>
using namespace std;
int main()
{

    //malloc  -->> void* malloc(size_t size)   // size_t datatype is stores only positive values like unsigned int
    //calloc  -->> void* calloc(size_t num,size_t size))
    //realloc -->> void* realloc(void* ptr, size_t size)  // first argument is pointer to the starting address of existing block.
    //free      //for deallocate block of memory

    // malloc example
    int *p = (int *)malloc(4 * sizeof(int));
    *p = 10;      //p[0]
    *(p + 1) = 4; //p[1]
    *(p + 2) = 5; //p[2]
    cout << p << endl;
    cout << p[3] << endl; // malloc initalize some garbage value to unassigned memory

    free(p);
    p = NULL;

    // calloc example
    int *x = (int *)calloc(3, sizeof(int));
    x[0] = 1;
    cout << x[0] << endl;
    cout << x[1] << endl; // calloc initalize zero(0) to unassigned memory
    free(p);
    p = NULL;

    // Example of malloc calloc and free with and without allcoating variable to memory
    int n;
    cin >> n;
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    int *B = (int *)calloc(n, sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    free(A);
    A = NULL;
    free(B);
    B = NULL;
    free(c);
    c = NULL;

    //realloc
    int *Arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        Arr[i] = i + 1;
    }

    int *D = (int *)realloc(Arr, (n / 2) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cout << D[i] << " ";
    }
    cout << endl;
    int *E = (int *)realloc(Arr, 0); // equivalent to free(Arr)
    for (int i = 0; i < n; i++)
    {
        cout << E[i];
    }

    int *F = (int *)realloc(NULL, n * sizeof(int)); // equivalent to malloc

    for (int i = 0; i < n; i++)
    {
        cout << F[i] << " ";
    }
    cout << endl;
    return 0;
}