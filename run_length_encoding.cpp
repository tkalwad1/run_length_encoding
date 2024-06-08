#include "run_length_encoding.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace run_length_encoding {
   string encode(string phrase){
        vector<char> characters;
        vector<char> coded;
        for(long unsigned int i = 0; i < phrase.size(); ++i){
            characters.push_back(phrase[i]);
        }
        
        
        char temp;
        int counter = 0;
  			vector<int> counter2;
        long unsigned int j = 0;
  			long unsigned int i = 0;
        while(j < characters.size()){
            temp = characters[j];
            for(i = j; i <= characters.size(); ++i){
                if(characters[i] == temp){
                    counter++;
                  	counter2.push_back(counter);
                }else{
                    j = i;
                    break;
                }
            }
            char counterChar = counter + '0';
            coded.push_back(counterChar);
            coded.push_back(temp);
          	if(counter2.size() >= characters.size()){
              break;
            }
            counter = 0;
        }
        
        
        coded.erase(remove(coded.begin(), coded.end(), '1'), coded.end()); 
        
        for(long unsigned int i = 0; i < coded.size(); ++i){
            cout <<coded[i];
        }
        cout << endl;
        
        string codedString;
        
        for(long unsigned int i = 0; i < coded.size(); ++i){
            codedString += coded[i];
        }
        
        cout << "Coded String Is: " << codedString << endl;
        return codedString;
    }

    string decode(string code){
        vector<char> codeVector;
        vector<char> decodedVector;

        for(long unsigned int i = 0; i < code.size(); ++i){
            codeVector.push_back(code[i]);
        }

        long unsigned int j = 0; 
        int multiple;
        int counter = 0;
        int counter2 = 0;

        if(codeVector[0] < 48 || codeVector[0] > 57){
            decodedVector.push_back(codeVector[0]);
        }
        while(j < codeVector.size()){
            //handles single digit numbers
            if(codeVector[j] >= 48 && codeVector[j] <= 57 && !(codeVector[j + 1] >= 48 && codeVector[j + 1] <= 57)){
                multiple = codeVector[j] - '0';
                while(counter < multiple){
                    decodedVector.push_back(codeVector[j + 1]);
                    counter++;
                }
                counter = 0;
            }
            //handles double digit 
            if(codeVector[j] >= 48 && codeVector[j] <= 57 && codeVector[j + 1] >= 48 && codeVector[j + 1] <= 57){
                multiple = (codeVector[j] - '0') * 10 + (codeVector[j + 1] - '0');
                while(counter2 < multiple){
                    decodedVector.push_back(codeVector[j + 2]);
                    counter2++;
                }
                break;
                counter2 = 0;
            }
            //handles single letter
            if((codeVector[j] < 48 || codeVector[j] > 57) && (codeVector[j + 1] < 48 || codeVector[j + 1] > 57) && (j != 0)){
                decodedVector.push_back(codeVector[j]);
            }
            ++j;
        }
        string decodedString;
        for(long unsigned int i = 0; i < decodedVector.size(); ++i){
            decodedString += decodedVector[i];
        }

        return decodedString;
    }
}  // namespace run_length_encoding
