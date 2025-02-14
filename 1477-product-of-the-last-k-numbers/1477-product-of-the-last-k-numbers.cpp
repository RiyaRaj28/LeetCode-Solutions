typedef long long ll; 
class ProductOfNumbers {
public:
    vector<ll>vec; 
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num); 
        
    }
    
    int getProduct(int k) {
        int n = vec.size(); 
        ll prod = 1; 

        for(int i=n-1; i>=n-k; i--)
        {
            prod *= vec[i]; 
        }
        return prod; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */