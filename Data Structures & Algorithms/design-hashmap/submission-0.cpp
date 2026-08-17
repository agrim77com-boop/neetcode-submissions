class MyHashMap {
public:
    vector <int> data;
    vector <bool> present;

    MyHashMap() {

        data.resize(1000001,0);
        present.resize(1000001,false);
    }
    
    void put(int key, int value) {

        data[key] = value;
        present[key] = true;
    }
    
    int get(int key) {

        if(present[key]){

            return data[key];
        }
        return -1;
    }
    
    void remove(int key) {

        present[key] = false;
        }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */