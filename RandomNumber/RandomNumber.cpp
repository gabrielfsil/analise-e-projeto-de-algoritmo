#include <random>
#include "RandomNumber.h"

using namespace std;

int RandomNumber::random(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);

    int number = dis(gen);

    return number;
}
