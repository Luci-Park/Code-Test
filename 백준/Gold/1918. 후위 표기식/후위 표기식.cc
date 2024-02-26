#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    string answer = "";
    string exps = "";
    stack<char> st;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        if('A' <= *it && *it <= 'Z')
            answer += *it;
        else if(*it == '+' || *it == '-')
        {
            while(!st.empty()&& st.top() != '(')
            {
                answer += st.top();
                st.pop();
            }
            st.push(*it);
        }
        else if(*it == '*' ||*it == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                answer += st.top();
                st.pop();
            }
            st.push(*it);
        }
        else if(*it == '(')
        {
            st.push(*it);
        }
        else if(*it == ')')
        {
            while(st.top() != '(')
            {
                answer+= st.top();
                st.pop();
            }
            st.pop();
        }
    }
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    cout << answer + exps;

    return 0;
}
