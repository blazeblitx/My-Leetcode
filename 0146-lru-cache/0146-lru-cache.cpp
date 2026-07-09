class Node{
public:
    int key,val;
    Node *prev,*next;

    Node(int k,int v){
        key=k;
        val=v;
    }
};

class LRUCache {
public:

    int cap;

    unordered_map<int,Node*> mp;

    Node *head,*tail;

    LRUCache(int capacity) {

        cap=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* node){

        Node* left=node->prev;
        Node* right=node->next;

        left->next=right;
        right->prev=left;
    }

    void insert(Node* node){

        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
    }

    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        Node* node=mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){

            Node* node=mp[key];

            node->val=value;

            remove(node);
            insert(node);

            return;
        }

        if(mp.size()==cap){

            Node* lru=tail->prev;

            remove(lru);

            mp.erase(lru->key);
        }

        Node* node=new Node(key,value);

        insert(node);

        mp[key]=node;
    }
};