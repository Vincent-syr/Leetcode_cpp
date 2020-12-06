#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <queue>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-06 17:32:08
 * @LastEditTime: 2020-12-06 17:37:50
 * @Description: file content
355. 设计推特   middle
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户
示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);


解法：
    用链表存储tweet消息，用unordered_map来存储user id和user对象之间的映射；
    getNewFeed要求消息按照时间顺序排列，即合并k个关注者的tweet有序链表：所用方法是Priority Queue
    ,数据结构是「二叉堆」最重要的应用

重点：priority_queue结构
        //构造大顶堆 时间最大的排在最上面
        priority_queue<Tweet*, vector<Tweet*>, cmp> q;

 */




int global_Time = 0;//发表推文的时间 全局的
//推文类
class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    
    Tweet(int id) {
        this->id = id;
        this->time = global_Time++;
        next = nullptr;
    }
};

//用户类
class User {
public:
    int id;
    Tweet *tweet; //该用户发送的推文 是个链表
    unordered_set<int> follows; //该用户关注的用户

    User(int id) {
        this->id = id;
        tweet = nullptr;
    }

    void follow(int followeeId) {
        //不能关注自己
        if (followeeId == id) return;
        follows.insert(followeeId);
    }

    void unfollow(int followeeId) {
        //没有关注 或者 不能取关自己
        if (!follows.count(followeeId) || followeeId == id) return;
        follows.erase(followeeId);
    }

    void post(int tweetId) {
        Tweet *newTweet = new Tweet(tweetId);
        //链表 采用头插法 新发表插在前面
        newTweet->next = tweet;
        //新的链表
        tweet = newTweet;
    }
};

class Twitter {    
private:
    unordered_map<int, User*> user_map;  //所有的用户
    
    bool contain(int id) {
        return user_map.find(id) != user_map.end();
    }
    
public:
    Twitter() {
        user_map.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            user_map[userId] = new User(userId);
        }
        //用户 发表 推文  面向对象
        user_map[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        //用户不存在
        if (!contain(userId)) return {};

        struct cmp {
            bool operator()(const Tweet *a, const Tweet *b) {
                return a->time < b->time;
            }
        };
        //构造大顶堆 时间最大的排在最上面
        priority_queue<Tweet*, vector<Tweet*>, cmp> q;

        //自己的推文链表
        if (user_map[userId]->tweet) {
            q.push(user_map[userId]->tweet);
        }
        //关注的推文链表
        for (int followeeId : user_map[userId]->follows) {
            if (!contain(followeeId)) {
                continue;
            }
            Tweet *head = user_map[followeeId]->tweet;
            if (head == nullptr) continue;
            q.push(head);
        }
        vector<int> rs;
        while (!q.empty()) {
            Tweet *t = q.top(); 
            q.pop();
            rs.push_back(t->id);
            if (rs.size() == 10) return rs;
            if (t->next) {
                q.push(t->next);
            }
        }
        return rs;
    }
    
    // 用户followerId 关注 用户followeeId.
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            user_map[followerId] = new User(followerId);
        }
        //面向对象
        user_map[followerId]->follow(followeeId);
    }
    
    // 用户followerId 取关 用户followeeId.
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        //面向对象
        user_map[followerId]->unfollow(followeeId);
    }
};


int main(int argc, char const *argv[])
{
    Twitter* obj = new Twitter();
    // obj->postTweet(userId,tweetId);
    // vector<int> param_2 = obj->getNewsFeed(userId);
    // obj->follow(followerId,followeeId);
    // obj->unfollow(followerId,followeeId);
    return 0;
}
