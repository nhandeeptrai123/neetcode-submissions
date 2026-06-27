class MyHashMap {
private:
    int numOfBucket;
    vector<vector<pair<int,int>>> buckets; //dùng để chứa cặp dữ liệu
    int hash(int key) {
        return key % numOfBucket; 
    }
public:
    MyHashMap() {
        numOfBucket = 1000;
        buckets.resize(numOfBucket);
    }
    
    void put(int key, int value) {
        int i = hash(key);
        for (auto &entry : buckets[i]) {
            //entry đóng vai trò là buckets[i][j]
            if (entry.first == key) {
                entry.second = value; 
                return;
            }
        }
        buckets[i].push_back({key,value});
        //Kiểm tra xem có sẵn key hay chưa, nếu chưa có thì nhập vào (key,value), không thì cập nhật value mới
    }
    
    int get(int key) {
        int i = hash(key);
        for (auto c : buckets[i]) {
            if (c.first == key) {
                return c.second; //Trả về giá trị tại key đó
            }
        }
        return -1; //Nếu không có thì trả về -1
    }
    
    void remove(int key) {
        int i = hash(key); 
        auto &bucket = buckets[i];
        for (auto it = bucket.begin(); it != bucket.end();it++) {
            if (it -> first == key) {
                bucket.erase(it); 
                return;
            }
        }
    }
    bool contains(int key) {
        int pos = hash(key);
        for (auto entry : buckets[pos]) {
            if (entry.first == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */