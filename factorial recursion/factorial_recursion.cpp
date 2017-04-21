#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

long int factorial (long int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
  {
    cout << "You have inserted negative value.\n";
    return 1;
  }
  if (n > 20)
  {
    cout << "Unfortunately my computance means are'nt sufficent for such a big values.\n";
    return 1;
  }
    long int miau = n * (factorial(n-1));
    cout << "\n" << miau;
return miau;
}

int main (void)
{
  cout << "Enter n, for n!:\n";
  long int n;
  cin >> n;
  n = factorial(n);
  cout << "\n" << n << "\n";
  return 0;
}
