#include <string>
#include <vector>

using namespace std;
int idx(char c)
{
    switch(c)
    {
        case 'R' : return 0;
        case 'T' : return 1;
        case 'C' : return 2;
        case 'F' : return 3;
        case 'J' : return 4;
        case 'M' : return 5;
        case 'A' : return 6;
        default : return 7;
    }
}
char character(int idx)
{
    switch(idx)
    {
        case 0 : return 'R';
        case 1 : return 'T';
        case 2 : return 'C';
        case 3 : return 'F';
        case 4 : return 'J';
        case 5 : return 'M';
        case 6 : return 'A';
        default : return 'N'; 
    }
}
string solution(vector<string> survey, vector<int> choice) {
    string answer = "";
    int count[8] = {0, };
    for(int i =0; i < survey.size(); i++)
    {
        if(choice[i] == 4) continue;
        if(choice[i] < 4) count[idx(survey[i][0])] += 4 - choice[i];
        else count[idx(survey[i][1])] += choice[i] - 4;
    }
    for(int i =0; i < 8; i+= 2)
    {
        if(count[i] > count[i + 1]) answer += character(i);
        else if(count[i] < count[i + 1]) answer += character(i + 1);
        else
        {
            answer += min(character(i), character(i + 1));
        }
    }
    
    return answer;
}