//headers
#include "PlaylistNode.h"

#include <iostream>
#include <string>


PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length){
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}

// accessors
string PlaylistNode::GetID() { 
  return uniqueID; 
}
string PlaylistNode::GetSongName() { 
  return songName; 
}
string PlaylistNode::GetArtistName() { 
  return artistName; 
}
int PlaylistNode::GetSongLength() { 
  return songLength; 
}
PlaylistNode* PlaylistNode::GetNext() { 
  return nextNodePtr; 
}

// mutators

//inserts a node after the current node 
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* temp = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = temp;
}

void PlaylistNode::insertAtEnd(PlaylistNode* newNode){
    if(this->nextNodePtr == nullptr){
        this->nextNodePtr=newNode;
        return;
    }

    PlaylistNode* tmp = this->nextNodePtr;

    while(tmp->nextNodePtr != nullptr){
        tmp = tmp->nextNodePtr;
    }
    tmp->nextNodePtr = newNode;
}

void PlaylistNode::removeByID(string Id){
    PlaylistNode* tmp = this->nextNodePtr;
    PlaylistNode* prev_temp = this;

    while(tmp->GetID() != Id && tmp!=nullptr){
        prev_temp = tmp;
        tmp = tmp->nextNodePtr;
    }
    if(tmp == nullptr){
        return;
    }
    PlaylistNode* tmpNext = tmp->nextNodePtr;
    prev_temp->nextNodePtr = tmpNext;
    cout<<"\""<<tmp->GetSongName()<<"\""<<" removed."<< "\n" << endl;
    delete tmp;

}

void PlaylistNode::printByArtist(string aName){
    PlaylistNode* tmp = this->nextNodePtr;
    int counter = 1;

    while(tmp != nullptr){
        if(tmp->GetArtistName()==aName){
            cout<<counter<<'.'<<endl;
            tmp->PrintPlaylistNode();
            cout<<endl;

        }
       
        counter++;
        tmp = tmp->nextNodePtr;
    }
}

void PlaylistNode::GetTime(){
    PlaylistNode* tmp = this->nextNodePtr;
    int tt =0;
    while(tmp != nullptr){
        tt += tmp->GetSongLength();
        tmp = tmp->nextNodePtr;
    }
    cout <<"Total time: "<<tt<< " seconds"<<endl<<endl;

}


//setting what the next node is
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

// print function
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
    }
