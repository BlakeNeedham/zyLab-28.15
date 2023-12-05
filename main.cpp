#include <iostream>
#include "PlaylistNode.h"
using namespace std;
int main(){

  string userTitle;
  cout << "Enter playlist's title: " << endl;
  cin >> userTitle;
  cout << userTitle;

  PlaylistNode::PrintMenu(userTitle);
  return 0;
}

//Remember you can skip step #9 which will  leave you with 21 points in the lab submission box in zyLabs (you get 6 additional points from posting lab on github).
//All group members must submit assignment through zyLabs (including the url to the github assignment) in order to get credit for the assignment. 
