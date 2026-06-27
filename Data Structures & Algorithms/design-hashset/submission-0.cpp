class MyHashSet {
 private: 
        int numBucket;
        vector<vector<int>> buckets;
        int hash(int key) {
            return key % numBucket; //chia lấy dư số cần tìm cho số lượng bucket, sau đó cho key đó vào bucket có số cần tìm
        }
    public:
        MyHashSet() {
            numBucket = 1000;
            buckets.resize(numBucket); //Tạo ra 1000 thùng, mỗi thùng chứa dữ liệu tùy ý
        }
    
        void add(int key) {
            int pos = hash(key);
            if (!contains(key))
            buckets[pos].push_back(key);
            //Bucket thứ pos sẽ chứa key    
        }
        
        void remove(int key) {
            int pos = hash(key); 
            if (contains(key)) {
            buckets[pos].erase(
            std::remove(buckets[pos].begin(), buckets[pos].end(), key), 
            buckets[pos].end()
    );      }
        }
        
        bool contains(int key) {
            int pos = hash(key);
            for (int i = 0; i < buckets[pos].size(); i++) {
                if (key == buckets[pos][i]) {
                    return true;
                }
            } 
            return false; 
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */