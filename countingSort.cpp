#include <iostream>
using namespace std;

int getMax(int a[])
{
    int max = a[0];
    for (int i = 0; i < max; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
int sort(int a[], int n)
{
    int max = getMax(&a[n]); // To find the max element
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i <= max; i++)
    { // To the count the number of elements of the array  a[] which will be stored in array count[]
        count[a[i]];
    }

    for (int i = 1; i <= max; i++)
    { // The cumiliative frequency will be stored here
        count[i] += count[i - 1];
    }
}

int main()
{
    int a[], n;
}