class Node{
    public:
    int value;
    int key;
    int occurence;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->value=value;
        this->key=key;
        occurence=1;
        next=NULL;
        prev=NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    int currentSize;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        currentSize=0;
    }
    void addNode(Node* node){
        Node* beforeTail=tail->prev;
        beforeTail->next=node;
        node->prev=beforeTail;
        node->next=tail;
        tail->prev=node;
        currentSize++;
    }
    void removeNode(Node* node){
        Node* previous=node->prev;
        Node* nex=node->next;
        previous->next=nex;
        nex->prev=previous;
        currentSize--;
    }
    Node* removeLFU(){
        Node* nextHead=head->next;
        Node* nextNextHead=nextHead->next;
        nextNextHead->prev=head;
        head->next=nextNextHead;
        currentSize--;
        return nextHead;
    }
};
class LFUCache {
public:
unordered_map<int, Node*> keyNode;
unordered_map<int, List*> freqList;
int minFreq;
int currentSize;
int capacity;
    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0;
        currentSize=0;
    }
    
    int get(int key) {
        if(keyNode.find(key)==keyNode.end())return -1;
        Node* node=keyNode[key];
        int occurence=node->occurence;
        List* l=freqList[occurence];
        l->removeNode(node);
        if(l->currentSize==0&&minFreq==occurence)
        minFreq++;
        node->occurence++;
        if(freqList.find(node->occurence)==freqList.end())
        {
            List* l=new List();
            freqList[node->occurence]=l;
        }
        freqList[node->occurence]->addNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key)==keyNode.end()){
            if(currentSize==capacity){
                List* l=freqList[minFreq];
                Node* node=l->removeLFU();
                keyNode.erase(node->key);
                delete(node);
                currentSize--;
            }
            Node* node=new Node(key,value);
            keyNode[key]=node;
            minFreq=1;
            if(freqList.find(1)==freqList.end())
            {
                List* l=new List();
                freqList[1]=l;
            }
            currentSize++;
            freqList[1]->addNode(node);
        }
        else{
            Node* node=keyNode[key];
            int occurence=node->occurence;
            List* l=freqList[occurence];
            l->removeNode(node);
            if(l->currentSize==0&&minFreq==occurence)
            minFreq++;
            node->occurence++;
            if(freqList.find(node->occurence)==freqList.end())
            {
                List* l=new List();
                freqList[node->occurence]=l;
            }
            freqList[node->occurence]->addNode(node);
            node->value=value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */