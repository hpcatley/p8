#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    if(k <= 0 || values.size()<k) {
        return -1;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> priorityQ;
    // https://en.cppreference.com/w/cpp/container/priority_queue#:~:text=A%20priority%20queue%20is%20a,appear%20as%20the%20top(). 
    // used above link to aid me with this bit
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