#include<bits/stdc++.h>
using namespace std;

class Twitter { // efficient solution
public:
    map<int,set<int>> followee; // userId -> {followees}
    vector<pair<int,int>> tweets; // <userId, tweetId>
    Twitter() { }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeeds;
        bool isFollowedNewsFeeds = false;
        for(int i=tweets.size()-1; i>=0;i--) { // traversing most recent to oldest tweet
            isFollowedNewsFeeds = userId == tweets[i].first || followee[userId].find(tweets[i].first) != followee[userId].end();
            if(isFollowedNewsFeeds) newsFeeds.push_back(tweets[i].second);
            if(newsFeeds.size()==10) break;
        }
        return vector<int>(newsFeeds.begin(), newsFeeds.begin() + min(10, (int) newsFeeds.size()));
    }
    
    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }

    void printNewsFeed(int userId) {
        vector<int> newsFeeds = getNewsFeed(userId);
        for(int newsFeed : newsFeeds) cout<<newsFeed<<" ";
        cout<<endl;
    }
};

struct Tweet {
    int userId;
    int tweetId;
    int time;
    Tweet() {}
    Tweet(int userId, int tweetId, int time): userId(userId), tweetId(tweetId), time(time) {}
    
    bool operator()(Tweet& tweet1, Tweet& tweet2) {
        return tweet1.time < tweet2.time;
    }
};

class TwitterUsingHeap { // using heap (less efficient)
public:
    int time = 0;
    map<int, pair<vector<Tweet>, set<int>>> data; 
    // userId -> pair<tweets,followee> 

    TwitterUsingHeap() {}

    void postTweet(int userId, int tweetId) {
        ++time;
        data[userId].first.push_back({userId, tweetId, time});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<Tweet> newsFeeds = data[userId].first;
        for(auto followee : data[userId].second) {
            newsFeeds.insert(newsFeeds.end(), data[followee].first.begin(), data[followee].first.end());
        }
        make_heap(newsFeeds.begin(), newsFeeds.end(), Tweet()); // max heap for maximizing time
        
        vector<int> result;
        int newsFeedsSize = newsFeeds.size();
        for(int i=0;i<newsFeedsSize && i<10;i++) {
            pop_heap(newsFeeds.begin(), newsFeeds.end(), Tweet());
            result.push_back(newsFeeds.back().tweetId);
            newsFeeds.erase(newsFeeds.end()-1);
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        data[followerId].second.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        data[followerId].second.erase(followeeId);
    }

    void printNewsFeed(int userId) {
        vector<int> newsFeeds = getNewsFeed(userId);
        for(int newsFeed : newsFeeds) cout<<newsFeed<<" ";
        cout<<endl;
    } 
};


int main() {
    Twitter twitter;
    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    twitter.postTweet(1,56);
    twitter.printNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    return 0;
}