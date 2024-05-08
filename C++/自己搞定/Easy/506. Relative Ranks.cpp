class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::priority_queue<std::pair<int,int>> pq;
        std::vector<std::string> goal{"","Gold Medal","Silver Medal","Bronze Medal"};
        std::vector<std::string> answer(score.size());
        for(int index=0;index<score.size();index++){
            pq.emplace(score[index],index);
        }
        int count = 1;
        while(!pq.empty()){
            std::pair<int,int> pair = pq.top();
            pq.pop();
            if (count<4) answer[pair.second]= goal[count];
            else answer[pair.second] = std::to_string(count);
            count++;
        }
        return answer;
    }
};