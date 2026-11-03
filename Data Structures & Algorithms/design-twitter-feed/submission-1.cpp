static const int _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Twitter {
private:
    struct TweetNode{
        int userId;
        int tweetId;
        int timestamp;
        int idx;

        TweetNode(int userId, int tweetId, int timestamp, int idx) : 
            userId(userId),
            tweetId(tweetId),
            timestamp(timestamp),
            idx(idx) 
        {}
        
    };
    unordered_set<int> followings[501];
    vector<TweetNode*> tweets_by_user[501];
    int timer;


public:    
    Twitter() {
        for(int i = 0; i<=500; i++){
            followings[i].clear();
            followings[i].insert(i);

            tweets_by_user[i].clear();
        }

        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        int idx = tweets_by_user[userId].size();
        tweets_by_user[userId].push_back( new TweetNode(userId,tweetId,timer++,idx)  );
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp = [this](const TweetNode* a, const TweetNode* b) {
            return a->timestamp < b->timestamp; // Max-Heap based on timer
        };

        priority_queue<
         TweetNode*, //pair<userid, index of last tweet;
         vector<TweetNode*>, 
         decltype(comp)
        > pq(comp);

        unordered_set<int>& following = followings[userId];
        for(int user:following){
            vector<TweetNode*>& user_tweets = tweets_by_user[user];
            
            int n_tweets;
            if( (n_tweets = user_tweets.size()) > 0 )
                pq.push(     user_tweets[n_tweets-1]     );

        }
        

        vector<int> feed; feed.reserve(10);

        while(feed.size()<10  && (!pq.empty())){
            TweetNode* tweet = pq.top();pq.pop();
            feed.push_back(tweet->tweetId);
            
            if(tweet->idx > 0){
                pq.push(    tweets_by_user[tweet->userId ][ (tweet->idx) - 1    ] );
            }
        }
        return feed;

    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        followings[followerId].erase(followeeId);
    }
};
