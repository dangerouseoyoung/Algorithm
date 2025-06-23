#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p1 = {1, 2, 3, 4, 5};
vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3, 0);
    for(int i = 0; i < answers.size(); i++){
        if(answers[i]==p1[i%5]) cnt[0]++;
        if(answers[i]==p2[i%8]) cnt[1]++;
        if(answers[i]==p3[i%10]) cnt[2]++;
    }
    
    auto it = max_element(cnt.begin(), cnt.end());
    int mx = *it;
    
    for(int i = 0; i < 3; i++){
        if(cnt[i]==mx) answer.push_back(i+1);
    }
    return answer;
}