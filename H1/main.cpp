#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

//tulostaa lukujen summan
void calcSum(int a, int b)
{
    cout << a << "+" << b << " = " << a + b << endl;
}

//tulostaa lukujen osamäärän kahdella desimaalilla
void calcDiv(int a, int b)
{
    if (b == 0) {
        cout << "Virhe: jakaja ei saa olla nolla!" << endl;
        return;
    }
    cout << a << "/" << b << " = "
         << fixed << setprecision(2) << static_cast<float>(a) / b << endl;
}

//palauttaa lukujen summan
int retSum(int a, int b)
{
    return a + b;
}

//palauttaa lukujen osamäärän
float retDiv(int a, int b)
{
    if (b == 0) {
        throw std::runtime_error("jakaja ei saa olla nolla!");
    }
    return static_cast<float>(a) / b;
}

int main()
{
    int a, b;

    cout << "Anna luku a: ";
    cin >> a;
    cout << "Anna luku b: ";
    cin >> b;

    // Tulostavat funktiot
    cout << "\ncalcSum ja calcDiv\n";
    calcSum(a, b);
    calcDiv(a, b);

    // Palauttavat funktiot
    cout << "\nretSum ja retDiv\n";
    int sum = retSum(a, b);
    cout << a << "+" << b << " = " << sum << endl;

    float result;
    //jos try-lohkossa tulee runtime error hyppää catch-lohkoon
    try {
        result = retDiv(a, b);
        cout << a << "/" << b << " = " << fixed << setprecision(2) << result << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
