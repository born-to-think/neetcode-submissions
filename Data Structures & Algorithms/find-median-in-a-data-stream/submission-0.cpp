class MedianFinder {

private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        left = priority_queue<int> ();
        left.push(INT_MIN);

        right = priority_queue<int, vector<int>, greater<int>> ();
        right.push(INT_MAX);
    }
    
    void addNum(int num) {
        if(num<left.top()){
            left.push(num);
            if( (left.size()-right.size()) >1 ){
                right.push(left.top());
                left.pop();
            }
        }else if(num > right.top()){
            right.push(num);
            if( (right.size()-left.size())>1 ){
                left.push(right.top());
                right.pop();
            } 
        }else{
            if(left.size()<=right.size()){
                left.push(num);
            }else{
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size()<right.size()){
            return (double) right.top();
        }else if(right.size()<left.size()){
            return (double) left.top();
        }
        else{
            return (left.top() + right.top()) / 2.0;
        } 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */