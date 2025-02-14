typedef long long ll; 
class ProductOfNumbers {
public:
    vector<ll>vec; 
    int size = 0; 
    ProductOfNumbers() {
        vec.push_back(1); 
        size = 0; 
    }
    
    void add(int num) {
        if(num == 0) 
        {
            vec = {1}; 
            size = 0; 
        }else 
        {
            vec.push_back(num*vec[size]); 
            size += 1; 
        }
    }
    
    int getProduct(int k) {
        // int n = vec.size(); 
        // ll prod = 1; 

        // for(int i=n-1; i>=n-k; i--)
        // {
        //     prod *= vec[i]; 
        // }
        // return prod; 
        

        if(size < k) return 0; 
         
        return (vec[size]/vec[size-k]); 
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */