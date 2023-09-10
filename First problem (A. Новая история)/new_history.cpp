#include <iostream>
#include <vector>
using namespace std;
int main()
{

    long long year[2], month[2], day[2], hour[2], minut[2], sec[2];
    cin >> year[0] >> month [0] >>  day[0] >> hour[0] >> minut[0] >> sec[0];
    cin >> year[1] >> month [1] >>  day[1] >> hour[1] >> minut[1] >> sec[1];
    long long month_d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long result1=0;
    for (long long i=0; i<month[0]-1; i++) { result1 += month_d[i] * 24 * 60 * 60; } //cout << result1 <<endl;
    result1+= year[0] * 365 * 24 * 60 * 60 + day[0] * 24 * 60 * 60 + hour[0] * 60 * 60 + minut[0] * 60 + sec[0];
    long long result2 = 0;
    for (long long i=0; i<month[1]-1; i++) { result2 += month_d[i] * 24 * 60 *60; } //cout << result2<< endl;
    result2+= year[1] * 365 * 24 * 60 * 60 + day[1] * 24 * 60 * 60 + hour[1] * 60 * 60 + minut[1] * 60 + sec[1];
    cout << (result2  - result1) / (60 * 60 * 24) << ' ' << ((result2 - result1) % (60 * 60 * 24));
}
