#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

class LZ77{
public:
    LZ77();
    vector <string> compress(string input, int dictSize, int bufferSize){
        int n = input.length();

        char charInput[n+1];
        strcpy(charInput, input.c_str());


    }
};

int main() {


    string word="aacaacabcabaaac", buff, dict;
    int buffSize=4;
    int dictSize=6;

    //cycles through the input word
    for (int i=0;i<word.length();i++){

        //adding new character to the buffer
        buff=buff+""+word[i];

        //if the buffer is less than its max size and it if not contained in the dictionary
        if(buff.length()<buffSize && dict.find(buff)==string::npos){

            //if the buffer is bigger that the dictionary
            if (buff.length()>dict.length() && dict.length()>0){

                //divides the buffer in pieces the biggest size possible that fit in the dictionary
                int slicecount = dict.length()/buff.length();

                //array for the buffer slices
                string slices[slicecount];

                //populates the slices array
                for (int i =0;i<slicecount; i++){
                    if (i<slicecount-1)
                        slices[i]=buff.substr(i*dict.length(),i*dict.length()+dict.length()-1);
                    else
                        slices[i]=buff.substr(i*dict.length(), i*dict.length()+1);
                }

                //flag to check if the last slice´s character is not contained in sequence in the dictionary
                bool newchar = false;

                for (int i=0;i<slices[slicecount-1].length();i++){
                    if (slices[slicecount-1][i]!=dict[i]){
                        newchar = true;
                        break;
                    }
                    else{
                        newchar = newchar;
                    }
                }

                //if there is a new character in sequence, output is set, the buffer is appended to the dictionary and buffer is cleared
                if (newchar){
                    cout<<"<"<<dict.length()-dict.find(slices[0])-1<<","<<buff.length()-1<<","<<buff[buff.length()-1]<<">"<<endl;
                    dict.append(buff);
                    buff = "";
                }
            //if the buffer is not bigger than dictionary
            }else{
                cout<<"<"<< dict.length()-dict.find(buff)-1<<","<<buff.length()-1<<","<<buff[buff.length()-1]<<">"<<endl;
                dict.append(buff);
                buff = "";
            }

            //if dictionary is bigger than max size, it is trimmed
            if (dict.length()>=dictSize)
                dict = dict.substr(dict.length()-dictSize,dict.length()-1);

            //if the buffer has reached max size
        } else if(buff.length()>=buffSize){
            if (buff.length()>dict.length()){
                int slicecount = dict.length()/buff.length();
                string slices[slicecount];
                for (int i =0;i<slicecount; i++){
                    if (i<slicecount-1)
                        slices[i]=buff.substr(i*dict.length(),i*dict.length()+dict.length()-1);
                    else
                        slices[i]=buff.substr(i*dict.length(), i*dict.length()+1);
                }

                //flag to check if the last slice´s character is not contained in sequence in the dictionary
                bool newchar = false;

                for (int i=0;i<slices[slicecount-1].length();i++){
                    if (slices[slicecount-1][i] != dict[i]){
                        newchar = true;
                        break;
                    }
                    else{
                        newchar = newchar;
                    }
                }
                //if there is a new character in sequence, output is set, the buffer is appended to the dictionary and buffer is cleared
                if (newchar){
                    cout<<"<"<<dict.length()-dict.find(slices[0])-1<<","<<buff.length()-1<<","<<buff[buff.length()-1]<<">"<<endl;
                    dict.append(buff);
                    buff = "";
                }
            } else{
                cout<<"<"<< dict.length()-dict.find(buff.substr(0,buff.length()))-1<<","<<buff.length()-1<<","<<buff[buff.length()-1]<<">"<<endl;
                dict.append(buff);
                buff = "";
                dict.append(buff);
            }

            if (dict.length()>=dictSize)
                dict = dict.substr(dict.length()-dictSize,dict.length()-1);
            buff ="";
        }
    }
    return 0;
}
