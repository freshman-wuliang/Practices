/*
*使用vector对象统计成绩
*使用vector对象的下标
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    vector<unsigned> scores_cnt(11,0);   //用于统计成绩分数段的vector对象
    unsigned grade;   //记录成绩

    while(cin >> grade)
    {
        if(grade <= 100)
        {
            scores_cnt[grade / 10]++;
        }
    }

    for(auto s : scores_cnt)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}