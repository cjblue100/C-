#include <iostream>

using namespace std;

int main()
{
    long num;
    int decimal=0, x=0, rem;

    cout << "Escriba numero binario: ";
    cin >> num;

    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        decimal += rem * pow(2, x);
        x++;
    }

    cout << "\nDecimal: " << decimal << "\n";

    
}