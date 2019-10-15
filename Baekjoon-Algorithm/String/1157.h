#include <algorithm>
#include <iostream>

using namespace std;

int descendingCompare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if (num1 > num2)
        return -1;
    else if (num1 < num2)
        return 1;
    else return 0;
}

void solve(){
   int alphabets[26] = {0, };
   string input;
   cin >> input;

   for(int i = 0; i < input.size(); i++){
       alphabets[tolower(input[i]) - 0x61]++;
   }

   char max = toupper(distance(alphabets, max_element(alphabets, alphabets + 26)) + 0x61);

   qsort(alphabets, 26, sizeof(int), descendingCompare);

   if(alphabets[0] == alphabets[1]){
       cout << "?";
   }
   else cout << max;

}
