class TaskManager {
public:
unordered_map<int,int> tp;
priority_queue<vector<int>> ump;
unordered_map<int,int> ut;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            ump.push({it[2],it[1],it[0]});
            tp[it[1]]=it[2];
            ut[it[1]]=it[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ump.push({priority,taskId,userId});
        tp[taskId]=priority;
        ut[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        tp[taskId]=newPriority;
        ump.push({newPriority,taskId,ut[taskId]});
    }
    
    void rmv(int taskId) {
        tp.erase(taskId);
        ut.erase(taskId);
    }
    
    int execTop() {
        while(ump.size()){
            auto it=ump.top();
            ump.pop();
            int p=it[0],t=it[1],ui=it[2];
            if(tp.find(t)!=tp.end()&&tp[t]==p){
                rmv(t);
                return ui;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */