/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop7: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

#include "SongCollection.h"

namespace sdds {

    void trim(string &str) {
        str.erase(str.find_last_not_of(' ') + 1);
        str.erase(0, str.find_first_not_of(' '));
    }

    SongCollection::SongCollection(string filename) {

        fstream file(filename);
        while (file) {

            string str, title, artist, album, year, length, price;
            Song sg;
            getline(file, str, '\n');

            title = str.substr(0, 25);
            str.erase(0, 25);

            artist = str.substr(0, 25);
            str.erase(0, 25);

            album = str.substr(0, 25);
            str.erase(0, 25);

            year = str.substr(0, 5);
            str.erase(0, 5);

            length = str.substr(0, 5);
            str.erase(0, 5);

            price = str.substr(0, 5);

            trim(title);
            trim(artist);
            trim(album);
            trim(year);
            trim(length);
            trim(price);


            // convert string to int using stream because stoi did not work for some reason
            stringstream ss(length);
            int l = 0;
            ss >> l;
            //
            int m = l / 60;
            int s = l % 60;

            sg.title = title;
            sg.artist = artist;
            sg.album = album;
            sg.year = year;
            sg.mins = to_string(m);
            sg.secs = to_string(s);
            sg.price = price;

            songs.push_back(sg);
        }
        songs.pop_back();
    }

    void SongCollection::display(ostream &os) const {
        for (auto i = songs.begin(); i != songs.end(); i++) {
            os << *i;
        }
    }

    ostream &operator<<(ostream &os, const Song &sg) {
        os << "| ";
        os << left << setw(20) << sg.title << " | ";
        os << left << setw(15) << sg.artist << " | ";
        os << left << setw(20) << sg.album << " | ";
        os << right << setw(6) << sg.year << " | ";
        os << sg.mins << ":";
        os << setw(2) << setfill('0') << sg.secs << setfill(' ') << " | ";
        os << sg.price << " |" << endl;
        return os;
    }
}
