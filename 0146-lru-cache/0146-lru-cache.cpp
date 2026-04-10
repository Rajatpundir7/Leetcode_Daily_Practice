struct Node{ 
        int key , val ;
        Node* prev , * next;
        Node(int k , int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

class LRUCache {
public:
        int capacity;
        unordered_map<int,Node*> cache;
        Node* head;
        Node* tail;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertfront(Node* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;

    }
    
    LRUCache(int cap) {
        capacity =  cap ;
       // unordered_map<int , Node*> mp;
        //Node *head , * tail;
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node*node = cache[key];
        remove(node);
        insertfront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insertfront(node);
            return;
        }
        if(cache.size() == capacity){
            Node *lru = tail->prev;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
           
        }
         Node* newnode = new Node(key,value);
            insertfront(newnode);
            cache[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */