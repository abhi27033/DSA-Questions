class LRUCache {
public:
struct Node
{
    Node* p;
    Node* n;
    int v;
    int k;
};
unordered_map<int,Node*> mp;
int c,cc;
Node* h=new Node();
Node* t=new Node();
void init()
{
h->p=NULL;
t->n=NULL;
h->n=t;
t->p=h;
}
void add(Node* nn)
{
   Node* temp=h->n;
    nn->n=temp;
    nn->p=h;
    h->n=nn;
    temp->p=nn;
}
void del(Node* nn)
{
    Node*t1=nn->n;
    Node*t2=nn->p;
    t1->p=t2;
    t2->n=t1;
    delete(nn);
}
    LRUCache(int capacity) {
        init();
        c=capacity;
        cc=0;
      
    }
    
    int get(int key) {
       if(mp.find(key)!=mp.end())
       {
           Node* bb=mp[key];
            int ans=bb->v;
          Node* nn=new Node();
            nn->v=ans;
            nn->k=key;
            mp.erase(key);
            del(bb);
            add(nn);
            mp[key]=h->n;
            return ans;
       }
       return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* bb=mp[key];
            mp.erase(key);
            del(bb);
            Node* nn=new Node();
            nn->v=value;
            nn->k=key;
            add(nn);
            mp[key]=h->n;
        }
        else
        {
            if(cc<c)
            {
            Node* nn=new Node();
            nn->v=value;
            nn->k=key;
            add(nn);
            mp[key]=h->n;
            cc++;
            }
            else
            {
            Node* g=t->p;
            mp.erase(g->k);
            del(g);
            Node* nn=new Node();
            nn->v=value;
            nn->k=key;
            add(nn);
            mp[key]=h->n;
            }
        }
    }
    // void hio()
    // {
        
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */