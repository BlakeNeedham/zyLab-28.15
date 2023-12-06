//URL for github repository https://github.com/BlakeNeedham/zyLab-28.15.git
//Team member 1 - Alyssa Burnett
//Team member 2 - Blake Needham
#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void OutputFullPlaylist(PlaylistNode* head) {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl << endl;
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

PlaylistNode* ExecuteMenu(char choice, string playlistTitle, PlaylistNode* head) {
    switch (choice) {

        case 'o': {
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

void PrintMenu(string playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
}

int main(){

    string playlistTitle;
    char userChoice;
    PlaylistNode* head = nullptr;

    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistTitle);
    
    while (true) {
        PrintMenu(playlistTitle);

        cout << "Choose an option:" << endl;
        cin >> userChoice;
       
        if (userChoice == 'q') {
            break;  
        }else if(userChoice == 'a' || 'd' || 'c' || 's' || 't' || 'o'){
             head = ExecuteMenu(userChoice, playlistTitle, head);
        }
    }

    return 0;
}





//Remember you can skip step #9 which will  leave you with 21 points in the lab submission box in zyLabs (you get 6 additional points from posting lab on github).
//All group members must submit assignment through zyLabs (including the url to the github assignment) in order to get credit for the assignment. 
