#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song {

private:
    string name;
    string artist;
    int size;

    static const int MAX_HANDICAP = 99;

public:

    Song();

    Song(string artist, string name, int size);

    string getName() const;

    void setName(string n);

    string getArtist() const;
    void setArtist(string a);
    int getSize() const;
    void setSize(int s);
    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);

};

ostream& operator << (ostream& out, const Song &g);


#endif