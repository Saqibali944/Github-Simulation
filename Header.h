#include<iostream>    //libraries used
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct filenode {
    string filename;
    filenode* nextFile;
    filenode(const string& filenm);
};
struct commitnode {
    string commitmessage;
    commitnode* nextcommit;
    filenode* filehead;
    commitnode(const string& commitmsg);
};
struct repo {
    string name;
    repo* left;
    repo* right;
    commitnode* commithead;
    repo(const string& nam);
};
struct User {
    string username;
    bool isLoggedIn;
    int numFollowers;
    repo* repository; //added member to associate repository with user
    User(const string& uname);
};
//define graph class for user relationships
class graph {
private:
    static const int MAX_USERS = 100;
    string users[MAX_USERS];
    bool followMatrix[MAX_USERS][MAX_USERS]; // Adjacency matrix for user relationships
    int numUsers;

public:
    graph();

    void addUser(const string& username);

    void followUser(const string& follower, const string& followee);

    void unfollowUser(const string& follower, const string& followee);

    void printGraph();

private:
    int findUserIndex(const string& username);
};

class hashtable {
private:
    User* table[100];
    graph usergraph;

public:
    hashtable();

    int hash(const string& key);

    int findUser(const string& username);

    //adding a new user
    void insertuser(const string& username);

    //login a user
    void loginuser(const string& username);

    //logout a user
    void logoutuser(string username);

    //getting user by username
    User* getUser(string username);

    //saving user data
    void saveusers(string filename);

    //delete repository for a user
    void deleterepository(string username);

    //view user profile
    void viewusers(string username);

    //adding new repository
    void createrepository(string username, string reponame);

    // Function to follow a user
    void followuser(string follower, string followee);

    // Function to unfollow a user
    void unfollowuser(string follower, string followee);
};
