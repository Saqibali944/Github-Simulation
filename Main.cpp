#include"Header.h"
// Main part
int main() {
    hashtable table;
    int c;
    do {
        cout << "--- GITHUB SIMULATION ---" << endl;
        cout << "Press 1 to add new user" << endl;
        cout << "Press 2 to login" << endl;
        cout << "Press 3 to logout" << endl;
        cout << "Press 4 to view user profile" << endl;
        cout << "Press 5 to save user data in file" << endl;
        cout << "Press 6 to create repository" << endl;
        cout << "Press 7 to delete repository" << endl;
        cout << "Press 8 to follow user" << endl;
        cout << "Press 9 to unfollow user" << endl;
        cout << "Press 0 to close program" << endl;
        cin >> c;
        switch (c) {
        case 1: {
            string username;
            cout << "Enter username" << endl;
            cin >> username;
            table.insertuser(username);
            break;
        }
        case 2: {
            string username;
            cout << "Enter username" << endl;
            cin >> username;
            table.loginuser(username);
            break;
        }
        case 3: {
            string username;
            cout << "Enter username: " << endl;
            cin >> username;
            table.logoutuser(username);
            break;
        }
        case 4: {
            string username;
            cout << "Enter username" << endl;
            cin >> username;
            table.viewusers(username);
            break;
        }
        case 5:
            table.saveusers("users.csv");
            break;
        case 6: {
            string username, repoName;
            cout << "Enter username" << endl;
            cin >> username;
            cout << "Enter repository name" << endl;
            cin >> repoName;
            table.createrepository(username, repoName);
            break;
        }
        case 7: {
            string username;
            cout << "Enter username" << endl;
            cin >> username;
            table.deleterepository(username);
            break;
        }
        case 8: {
            string follower, followee;
            cout << "Enter follower's username" << endl;
            cin >> follower;
            cout << "Enter followee's username" << endl;
            cin >> followee;
            table.followuser(follower, followee);
            break;
        }
        case 9: {
            string f1, f2;
            cout << "Enter follower's username" << endl;
            cin >> f1;
            cout << "Enter followee's username" << endl;
            cin >> f2;
            table.unfollowuser(f1, f2);
            break;
        }
        case 0:
            cout << "BYE!!!!!!" << endl;
            break;
        default:
            cout << "Incorrect option entered" << endl;
        }
    } while (c != 0);
    system("pause");
    return 0;
}