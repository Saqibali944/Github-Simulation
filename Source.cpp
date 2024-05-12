#include"Header.h"
 graph::graph() : numUsers(0) {
    for (int i = 0; i < MAX_USERS; ++i) {
        users[i] = "";
        for (int j = 0; j < MAX_USERS; ++j) {
            followMatrix[i][j] = false;
        }
    }
}

 void graph::addUser(const string& username) {
    if (numUsers < MAX_USERS) {
        users[numUsers++] = username;
    }
}

 void graph::followUser(const string& follower, const string& followee) {
    int followerIndex = findUserIndex(follower);
    int followeeIndex = findUserIndex(followee);
    if (followerIndex != -1 && followeeIndex != -1) {
        followMatrix[followerIndex][followeeIndex] = true;
    }
}

 void graph::unfollowUser(const string& follower, const string& followee) {
    int followerIndex = findUserIndex(follower);
    int followeeIndex = findUserIndex(followee);
    if (followerIndex != -1 && followeeIndex != -1) {
        followMatrix[followerIndex][followeeIndex] = false;
    }
}

 void graph::printGraph() {
    cout << "User Graph:\n";
    cout << "   ";
    for (int i = 0; i < numUsers; ++i) {
        cout << users[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < numUsers; ++i) {
        cout << users[i] << " ";
        for (int j = 0; j < numUsers; ++j) {
            cout << (followMatrix[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
}

 int graph::findUserIndex(const string& username) {
    for (int i = 0; i < numUsers; ++i) {
        if (users[i] == username) {
            return i;
        }
    }
    return -1; // User not found
}

 hashtable::hashtable() {
    for (int i = 0; i < 100; ++i) {
        table[i] = nullptr;
    }
}

 int hashtable::hash(const string& key) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return (sum % 100);
}

//adding a new user

 int hashtable::findUser(const string& username) {
    int index = hash(username);
    int originalIndex = index;
    while (table[index] != nullptr && table[index]->username != username) {
        index = (index + 1) % 100;
        if (index == originalIndex) {
            return -1; // if user not found
        }
    }
    return index;
}

 void hashtable::insertuser(const string& username) {
    int index = hash(username);
    while (table[index] != nullptr) {
        index = (index + 1) % 100; //linear probing
    }
    table[index] = new User(username);
}

//login a user

 void hashtable::loginuser(const string& username) {
    int index = findUser(username);
    if (index != -1) {
        table[index]->isLoggedIn = true; // Fixed typo
        cout << "Login successful " << endl;
    }
    else {
        cout << "Unable to login";
    }
}

//logout a user

 void hashtable::logoutuser(string username) {
    int index = findUser(username);
    if (index != -1) {
        table[index]->isLoggedIn = false;
    }
}

//getting user by username

 User* hashtable::getUser(string username) {
    int index = findUser(username);
    return (index != -1) ? table[index] : nullptr;
}

//saving user data

 void hashtable::saveusers(string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    for (int i = 0; i < 100; ++i) {
        if (table[i] != nullptr) {
            file << table[i]->username << "," << table[i]->isLoggedIn << "," << table[i]->numFollowers << endl;
        }
    }
    file.close();
    cout << "User data saved to " << filename << endl;
}

//delete repository for a user

 void hashtable::deleterepository(string username) {
    User* user = getUser(username);
    if (user != nullptr && user->repository != nullptr) {
        delete user->repository;
        user->repository = nullptr;
    }
}

//view user profile

 void hashtable::viewusers(string username) {
    User* user = getUser(username);
    if (user != nullptr) {
        cout << "Username: " << user->username << endl;
        cout << "Is Logged In: ";
        if (user->isLoggedIn) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        cout << "Number of Followers: " << user->numFollowers << endl;
    }
}

//adding new repository

 void hashtable::createrepository(string username, string reponame) {
    User* user = getUser(username);
    if (user != NULL && user->repository == NULL) {
        user->repository = new repo(reponame);
    }
}

// Function to follow a user

 void hashtable::followuser(string follower, string followee) {
    usergraph.followUser(follower, followee);
    cout << "Followed user!";
}

// Function to unfollow a user

 void hashtable::unfollowuser(string follower, string followee) {
    usergraph.unfollowUser(follower, followee);
    cout << "Unfollowed user!";
}

 commitnode::commitnode(const string& commitmsg) {
    commitmessage = commitmsg;
    filehead = NULL;
    nextcommit = NULL;
}

 repo::repo(const string& nam) {
    name = nam;
    left = NULL;
    right = NULL;
    commithead = NULL;
}

 filenode::filenode(const string& filenm) {
    filename = filenm;
    nextFile = NULL;
}

//added member to associate repository with user
 User::User(const string& uname) : username(uname), isLoggedIn(false), numFollowers(0), repository(nullptr) {}
