#define pii pair<int,int>

class TaskManager {
public:

    unordered_map<int,pii> mp;
    priority_queue<pii> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks)
        {
            int uid = it[0];
            int tid = it[1];
            int p = it[2];

            pq.push({p,tid});
            mp[tid] = {uid,p};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        if(mp.find(taskId) != mp.end()) {
            int uid = mp[taskId].first;
            pq.push({newPriority, taskId}); // Push the updated priority
            mp[taskId] = {uid, newPriority};
        }
    }
    
    void rmv(int taskId) {
        if(mp.find(taskId) != mp.end()) {
            mp.erase(taskId); // Remove from the map
        }
    }
    
    int execTop() {
        while(!pq.empty()) {
            auto [p, tid] = pq.top();
            pq.pop();
            if(mp.find(tid) != mp.end() && mp[tid].second == p) {
                int uid = mp[tid].first;
                mp.erase(tid); // Remove task after execution
                return uid;
            }
        }
        return -1; // If no valid tasks are found
    }
};
