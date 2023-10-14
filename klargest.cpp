#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    if(k <= 0) {
        return -1;
    }
    std::priority_queue<int> priorityQ;
    for (int value : values) {
        if(priorityQ.size() < k) {
            priorityQ.push(value); 
        }
        else {
            if(value > priorityQ.top()) {
                priorityQ.pop();
                priorityQ.push(value);
            }
        }
    }
    return priorityQ.top();


}