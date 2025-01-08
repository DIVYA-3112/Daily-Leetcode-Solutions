#define pii pair<int,int>

class Twitter {
public:
    unordered_map<int, set<int>> followList; // Follower -> Followees
    unordered_map<int, vector<pii>> tweets; // UserId -> (Time, TweetId)
    priority_queue<pii> pq; // (Time, TweetId)
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // Create a priority queue to merge tweets
        priority_queue<pii> pq;

        // Add user's own tweets
        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add tweets from followees
        for (int followee : followList[userId]) {
            for (auto& tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        // Extract the top 10 tweets
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // Prevent self-follow
            followList[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
