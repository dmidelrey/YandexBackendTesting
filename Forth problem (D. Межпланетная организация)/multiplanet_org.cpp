#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct Employee {
    int id;
    char language;
    int manager;
    int barrierA;
    int barrierB;
    Employee(int id, char language, int manager) : id(id), language(language), manager(manager), barrierA(0), barrierB(0) {}
};

int main() {
    int N;
    cin >> N;

    vector<Employee> employees;
    employees.emplace_back(0, 'K', -1);
    for (int i = 1; i <= N; ++i) {
        char language;
        cin >> language;
        employees.emplace_back(i, language, -1);
    }
    stack <int> sc;
    vector<int> hierarchy(2 * (N + 1));
    for (int i = 0; i < 2 * (N + 1); ++i) {
        cin >> hierarchy[i];
        int id = hierarchy[i];
        // cout << "id " << id;
        if (i == 0) sc.push(id);
        else {
            if (sc.top() != id)
                {
                    if (employees[sc.top()].language != employees[id].language)
                    {
                        if (employees[id].language == 'A') { employees[id].barrierA = employees[sc.top()].barrierA + 1; employees[id].barrierB = 1; }
                        if (employees[id].language == 'B') { employees[id].barrierB = employees[sc.top()].barrierB + 1; employees[id].barrierA = 1; }
                    }
                    else
                    {
                        if (employees[id].language == 'A') { employees[id].barrierA = 1; employees[id].barrierB = employees[sc.top()].barrierB + 1; }
                        if (employees[id].language == 'B') { employees[id].barrierB = 1; employees[id].barrierA = employees[sc.top()].barrierA+1; }
                    }
                    //cout << "A " << employees[id].barrierA << ' ' << "B " << employees[id].barrierB << "top " << employees[sc.top()].barrierA << endl;
                    sc.push(id);
                }
            else
            {
                sc.pop();
                if (id > 0) {
                    employees[id].manager = sc.top();
                }
                // cout << "id " << id << "lang " << language << "man " << sc.top() << endl;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (employees[i].language == 'A') cout << employees[i].barrierA-1 << ' ';
        else cout << employees[i].barrierB-1 << ' ';
    }
    return 0;
}
