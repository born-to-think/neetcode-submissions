class Node{
public:
    // to implement
    int key=0;
    int val=0;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    Node(){}

    Node(int k, int v){
        key=k;
        val=v;
    }
};


class LRUCache {
public:
    unordered_map<int,Node*> cache;
    int cap;

    //initialising doublink list
    Node* left_end = new Node();
    Node* right_end = new Node();
    
    LRUCache(int capacity) {
        cap = capacity;
        left_end->next = right_end;
        right_end->prev= left_end;
    }

    void insert(Node* node){
        node->next = right_end;
        node->prev = right_end->prev;
        right_end->prev->next = node;
        right_end->prev=node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            //Update the recentivity
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]->val=value;
            remove(cache[key]);
            insert(cache[key]);
        }
        else{
            Node* newNode=new Node(key,value);
            cache[key] = newNode;
            insert(newNode);

            if(cache.size()>cap){
                Node* lru = left_end->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }

        }
    }
};
