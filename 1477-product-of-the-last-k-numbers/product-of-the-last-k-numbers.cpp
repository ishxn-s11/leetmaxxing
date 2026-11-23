/*Brute Force*/

class ProductOfNumbers {
public:
    vector<int>mult;

    ProductOfNumbers() {
    }
    
    void add(int num) {
        mult.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int n=mult.size();

        for(int i=n-k;i<n;i++) prod*=mult[i];

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */