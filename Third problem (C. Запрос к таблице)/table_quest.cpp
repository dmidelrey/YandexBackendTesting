// Это решение не прошло по времени на 32 тесте
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>
#include <experimental/vector>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    size_t rows, cols, actions;
    cin >> rows >> cols >> actions;

    unordered_map<string, int> cols_name;
    for (size_t i = 0; i < cols; i++)
    {
        string temp;
        cin >> temp;
        cols_name[temp] = i;
    }

    list<vector<int>> arr;
    for (int i=0; i<rows; i++)
    {
        vector<int> tmp(cols);
        for (size_t j = 0; j < cols; j++)
        {
            cin >> tmp[j];
        }
        arr.push_back(tmp);
    }

    string tmp;
    char oper;
    int constraint;

    auto it = arr.end();

    for (size_t i = 0; i < actions; i++)
    {
        cin >> tmp >> oper >> constraint;

        int index = cols_name[tmp];

        it = remove_if(arr.begin(), it, [index, constraint, oper](auto element)
            {
                return (oper == '<') ? (element[index] >= constraint) : (element[index] <= constraint);
            });

    }

    int result = 0;
    for (auto it1 = arr.begin(); it1 != it; it1++)
    {
        result = accumulate((*it1).begin(), (*it1).end(), result);
    }

    cout << result;
}
