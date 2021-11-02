#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {

    string word = "aacaacabcabaaac", buff, dict;
    int buffMaxSize = 4;
    int dictMaxSize = 6;

    for (char i: word) {
        buff = buff + "" + i;
        cout << "new cycle" << " + " << i << endl;

        if (buff.length() == 1 && dict.find(buff) == string::npos) {
            dict.append(buff);
            cout << "<" << 0 << ",0," << buff << ">" << endl;
            buff = "";
            if (dict.length() > dictMaxSize) {
                dict = dict.substr(dict.length() - dictMaxSize, dict.length());
            }
            cout << "dictionary: " << dict << endl;
        } else if (dict.find(buff) == string::npos) {
            if (buff.length() >= dict.length()) {
                int mult = buff.length() / dict.length();
                int module = buff.length() % dict.length();
                int lowerLimit = mult * dict.length() - 1 + module;
                string lastslice = buff.substr(lowerLimit, dict.length());
                bool newchar = false;
                for (int i = 0; i < lastslice.length(); i++) {
                    if (lastslice[i] != dict[i]) {
                        newchar = true;
                        break;
                    }
                }

                if (newchar || buff.length() > buffMaxSize) {
                        cout << "<" << dict.length() - dict.find(buff.substr(0, dict.length()))
                         << "," << buff.length() - 1 << "," << buff[buff.length() - 1] << ">" << endl;
                    dict.append(buff);
                    buff = "";
                    if (dict.length() > dictMaxSize) {
                        dict = dict.substr(dict.length() - dictMaxSize, dict.length());
                    }
                    cout << "dictionary: " << dict << endl;
                }
            } else if (buff.length() > buffMaxSize) {
                string match = buff.substr(0, buffMaxSize);
                cout << "<" << dict.length() - dict.find(match) << "," << buff.length() - 1
                     << "," << buff[buff.length() - 1] << ">" << endl;
                dict.append(buff);
                buff = "";
                if (dict.length() > dictMaxSize) {
                    dict = dict.substr(dict.length() - dictMaxSize, dict.length());
                }
                cout << "dictionary: " << dict << endl;
            } else if (buff.length() == buffMaxSize) {

                string match = buff.substr(0, buffMaxSize - 1);
                cout << "<" << dict.length() - dict.find(match) << "," << buff.length() - 1
                     << "," << buff[buff.length() - 1] << ">" << endl;
                dict.append(buff);
                buff = "";
                if (dict.length() > dictMaxSize) {
                    dict = dict.substr(dict.length() - dictMaxSize, dict.length());
                }
                cout << "dictionary: " << dict << endl;
            }
        }


    }
    if (buff.length() > 0) {
        cout<<"dic length:"<< dict.length() << endl;
        cout<<"found at: "<<dict.find(buff[0])<<endl;
        cout << "<" << dict.length() - dict.find(buff[0]) << "," << buff.length() - 1 << ","
             << buff[buff.length() - 1] << ">" << endl;
        buff = "";
        dict = dict.substr(dict.length() - dictMaxSize, dict.length());
        cout << "dictionary: " << dict << endl;
        cout << "last" << endl;
    }
    return 0;
}
