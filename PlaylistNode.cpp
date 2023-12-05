//headers
#include "PlaylistNode.h"

#include <iostream>
#include <string>

// defualt constructor - sets the values to basically nothing
PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

// parameterized constructor - sets the actual values of these to the inputs
PlaylistNode::PlaylistNode(string& id, string& name, string& artist, int length)
    : uniqueID(id), songName(name), artistName(artist), songLength(length), nextNodePtr(nullptr) {}

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

