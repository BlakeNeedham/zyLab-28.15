//headers
#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
    public:
    // default constructor
    PlaylistNode();

    // parameterized constructor
    PlaylistNode(string id, string name, string artist, int length);

    // accessors
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();

    // mutators
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    void insertAtEnd(PlaylistNode* newNode);
    void removeByID(string Id);
    

    // print function
    void PrintPlaylistNode();
    void printByArtist(string aName);
    void GetTime();

  private: 
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};
#endif
