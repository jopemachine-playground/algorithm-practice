#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int finding = -1;
    int excludeIdx = k + 1;

    while (excludeIdx <= number.length())
    {
        int maxDigit = -1;

        for (int j = finding + 1; j < excludeIdx && j < number.length(); ++j)
        {
            int jthValue = number.at(j) - '0';

            if (maxDigit < jthValue)
            {
                maxDigit = jthValue;
                finding = j;
            }
        }
        
        answer += to_string(maxDigit);
        ++excludeIdx;
    }

    return answer;
}