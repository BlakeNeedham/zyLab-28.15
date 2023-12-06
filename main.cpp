#include <iostream>
#include "PlaylistNode.h"
using namespace std;
int main(){

    string playlistTitle;
    string userChoice;
    PlaylistNode* head = nullptr;

    cout << "Enter playlist's title:" << endl;
    cin >> playlistTitle;
  
    while (true) {
        PrintMenu(playlistTitle);

        cout << "Choose an option: ";
        cin >> userChoice;
       
        if (userChoice == 'q') {
            break;  
        }else if(userChoice == "a" || "d" || "c" || "s" || "t" || "o"){
             head = ExecuteMenu(userChoice, playlistTitle, head);
        }
    }

    return 0;
}

void OutputFullPlaylist(PlaylistNode* head) {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }

    int position = 1;
    PlaylistNode* current = head;
    while (current != nullptr) {
        cout << position << ".\n";
        current->PrintPlaylistNode();
        cout << endl;

        current = current->GetNext();
        position++;
    }
}

PlaylistNode* ExecuteMenu(string choice, string playlistTitle, PlaylistNode* head) {
    switch (choice) {

        case "o": {
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            OutputFullPlaylist(head);
            break;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return head;
}

//Remember you can skip step #9 which will  leave you with 21 points in the lab submission box in zyLabs (you get 6 additional points from posting lab on github).
//All group members must submit assignment through zyLabs (including the url to the github assignment) in order to get credit for the assignment. 
