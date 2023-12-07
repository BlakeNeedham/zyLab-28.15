//URL for github repository https://github.com/BlakeNeedham/zyLab-28.15.git
//Team member 1 - Alyssa Burnett
//Team member 2 - Blake Needham
#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void OutputFullPlaylist(PlaylistNode* head) {

    PlaylistNode* tmp = head;

    int position = 1;


    if(tmp->GetNext() == nullptr){
        cout << "Playlist is empty" << endl << endl;
        return;
    }

    tmp = tmp->GetNext();
    while (tmp != nullptr) {
            
            cout << position << ".\n";
            tmp->PrintPlaylistNode();
            cout << endl;

            tmp = tmp->GetNext();
            position++;
        }
    
    
}
void ExecuteMenu(char choice, string playlistTitle, PlaylistNode* head) {
    if(choice == 'o'){

        
        cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

        OutputFullPlaylist(head);

        
            
    }else if(choice == 'a'){
        string ID, songN, artistN,songL;
            cout<<endl;
            cout << "ADD SONG"<< endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, ID);
            //cin >> ID;
            cout << "Enter song's name:" << endl;
            getline(cin, songN);
            //cin >> songN;
            cout << "Enter artist's name:" << endl;
            getline(cin, artistN);
            //cin >> artistN;
            cout << "Enter song's length (in seconds):" << endl;
            cout<<endl;
            getline(cin, songL);
            int sl = stoi(songL);
            //cin >> songL;
            
            PlaylistNode* newN = new PlaylistNode(ID, songN, artistN, sl);
            head->insertAtEnd(newN);

    }else if(choice == 'd'){
        string songID;
        cout<<"REMOVE SONG"<<endl;
        cout<<"Enter song's unique ID:"<<endl;
        getline(cin, songID);
        //cin >> songID;
        head->removeByID(songID);

    }else if(choice == 's'){
        string aName;
        cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
        cout<<"Enter artist's name:"<<endl<<endl;
        getline(cin, aName);
        //cin>>aName;
        head->printByArtist(aName);
    }else if(choice == 't'){
        cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
        head->GetTime();
    }else{
        cout << "Invalid choice. Please try again." << endl;
    }

    //return head;
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
    string ui;
    PlaylistNode* head = new PlaylistNode();

    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistTitle);
    
    while (true) {
        PrintMenu(playlistTitle);

        cout << "Choose an option:" << endl;
        getline(cin, ui);
        userChoice = ui[0];
        //cin >> userChoice;
       
        if (userChoice == 'q') {
            break;  
        }else if(userChoice == 'a' || userChoice =='d' || userChoice =='c' || userChoice =='s' || userChoice =='t' || userChoice =='o'){
            ExecuteMenu(userChoice, playlistTitle, head);
        }
    }

    return 0;
}
