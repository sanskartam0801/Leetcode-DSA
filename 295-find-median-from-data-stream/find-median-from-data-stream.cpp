class MedianFinder {
public:
    int total = 0;
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) left_max_heap.push(num);
        else right_min_heap.push(num);

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        total++;
    }
    
    double findMedian() {
        if(total%2==0){
            int a = left_max_heap.top();
            int b = right_min_heap.top();
            return (a+b)/2.0;
        }
        else{
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */