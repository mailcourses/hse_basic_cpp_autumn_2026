#include <unordered_map>
#include <vector>
#include <iostream>
#include <random>
#include <cassert>

class RandomizedSet {
private:
    std::unordered_map<int, int> kv;
    std::vector<int> keys;
public:
    RandomizedSet(){
        
    }
    
    bool insert(int val) {
        if (kv.contains(val)){
            return false;
        }
        keys.push_back(val);
        kv[val] = keys.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!kv.contains(val)){
            return false;
        }
        int cur_idx = kv[val];
        std::swap(keys[cur_idx], keys.back());
        keys.pop_back();
        kv.erase(val);
        kv[keys[cur_idx]] = cur_idx;
        return true;
    }
    
    int getRandom() {
        if (kv.empty()){
            return 0;
        }
        std::random_device r;
        // Choose a random mean between 1 and 6
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(0, kv.size()-1);
        int mean = uniform_dist(e1);
        return keys[mean];
    }
};

int main()
{
    RandomizedSet set;
    for (auto num : {1,2,9,10})
    {
        assert(set.insert(num) == true);
    }
    
    for (auto num : {1,2,9,10})
    {
        assert(set.insert(num) == false);
    }
    
    for (size_t i = 0; i < 8; ++i)
    {
        std::cout << set.getRandom() << std::endl;
    }
    
    for (auto num : {1,2,9,10})
    {
        assert(set.remove(num) == true);
    }
    
    for (auto num : {1,2,9,10})
    {
        assert(set.remove(num) == false);
    }
}
