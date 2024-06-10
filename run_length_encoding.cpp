#include "run_length_encoding.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace run_length_encoding {
   string encode(string input) {
       string final_output = "";
       if (input.size() == 0) {
           return "";
       } else {
           if (input.size() == 1) {
               return input;
           } else {
               int current_index = 0;
               int next_index = 1;
               char current_char = input[current_index];
               char next_char = input[next_index];
               int same_char_counter = 1;
               while (next_index <= input.size() -1) {
                   if (input[current_index] == input[next_index]) {
                       same_char_counter = same_char_counter + 1;
                       current_index = current_index + 1;
                       next_index = next_index + 1;
                   } else {
                       string counter_to_char = to_string(same_char_counter);
                       if (same_char_counter > 1) {
                           final_output = final_output + counter_to_char + input[current_index];
                       } else {
                           final_output = final_output + input[current_index];
                       }
                       same_char_counter = 1;
                       current_index = current_index + 1;
                       next_index = next_index + 1;
                   }
               }
               string counter_to_char = to_string(same_char_counter);
               if (same_char_counter > 1) {
                   final_output = final_output + counter_to_char + input[current_index];
               } else {
                   final_output = final_output + input[current_index];
               }
           }
       }
       
       return final_output;
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
