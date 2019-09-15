/*
==============================+===============================================================
@ File Name : 1946.h
@ Author : jopemachine
@ Desc : 
@    신입 사원
@    A 점수로 오름차순으로 정렬해 준 다음 B 점수에서 내림차순에 어긋나는 인원들을
@    제외하니 쉽게 풀림.
==============================+===============================================================
*/
#ifndef ALGORITHM_1946_H
#define ALGORITHM_1946_H

#include <iostream>

using namespace std;

typedef struct{
    int grade_A;
    int grade_B;
} Grade;

int ascendingCompare(const void* a, const void* b)
{
    Grade num1 = *(Grade*) a;
    Grade num2 = *(Grade*) b;

    if (num1.grade_A > num2.grade_A)
        return 1;
    else if (num1.grade_A < num2.grade_A)
        return -1;
    else return 0;
}

void solve_1946(){

    ios::sync_with_stdio(false);

    int T, N;

    cin >> T;

    int result[T];

    Grade* gradeArr;

    for (int i = 0; i < T; i++){
        cin >> N;

        gradeArr = new Grade[N];

        for(int j = 0; j < N; j++){
            cin >> gradeArr[j].grade_A >> gradeArr[j].grade_B;
        }

        qsort( gradeArr, N, sizeof(Grade), ascendingCompare );

        int minGradeB = gradeArr[0].grade_B;
        int dropOut = 0;

        for(int j = 1; j < N; j++){
            if(gradeArr[j].grade_B < minGradeB){
                minGradeB = gradeArr[j].grade_B;
            }
            else {
                dropOut++;
            }
        }

        result[i] = N -dropOut;

        delete gradeArr;
    }

    for (int i = 0; i < T; i++){
        if(i == T - 1){
            cout << result[i];
        }
        else {
            cout << result[i] << "\n";
        }
    }

}
#endif //ALGORITHM_1946_H
