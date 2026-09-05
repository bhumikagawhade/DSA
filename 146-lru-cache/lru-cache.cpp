class Node{
    public: 

    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key = key;
        this->val=val;
        prev=NULL;
        next = NULL;

    }
};

class LRUCache {

    int cap;
    Node* head;
    Node* tail;

    unordered_map<int,Node*> mp;

    void addfirst(Node* node){
        Node* currafterhead = head->next;
        head->next = node;
        node->next = currafterhead;
        node->prev = head;
        currafterhead->prev = node;
    }

    void deletenode(Node* node){
        Node* prevnode = node->prev;
        Node* afternode = node->next;
        prevnode->next = afternode;
        afternode->prev = prevnode;
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
           return -1;
        }

        Node* node = mp[key];
        deletenode(node);
        addfirst(node);

        return node->val;

    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;

            deletenode(node);
            addfirst(node);
            return;
        }

        else{
            if(mp.size() >= cap){
                Node* lru = tail->prev;
                deletenode(lru);
                mp.erase(lru->key);
            }

            Node* newnode = new Node(key,value);
            addfirst(newnode);
            mp[key] = newnode;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */