class KthLargest {
private:
    int k;
    vector<int> nums;
public:

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        make_heap(nums.begin(), nums.end(), greater<int>());
        while(nums.size()>k){
            pop_heap(nums.begin(), nums.end(),greater<int>());
            nums.pop_back();
        }
        this->nums=move(nums);
    }
    
    int add(int val) {
        nums.push_back(val);
        push_heap(nums.begin(), nums.end(), greater<int>());

        while(nums.size()>k){
            pop_heap(nums.begin(), nums.end(),greater<int>());
            nums.pop_back();
        }
        return nums.front();
    }
};
