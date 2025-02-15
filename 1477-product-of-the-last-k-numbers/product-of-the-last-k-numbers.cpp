class ProductOfNumbers {
public:

    vector<int> nums;
    int k = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0)
        {
            nums.clear();
            k = 1;
        }
        else
        {
            k = k * num;
            nums.push_back(k);
        }
    }
    
    int getProduct(int k) {
        if(nums.size() < k) return 0;
        else if(nums.size() == k) return nums[k-1];
        else
        {
            int a = nums.back();
            int b = nums[nums.size()-k-1];
            return a/b;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */