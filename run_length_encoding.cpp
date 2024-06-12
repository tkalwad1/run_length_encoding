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
               long unsigned int current_index = 0;
               long unsigned int next_index = 1;
               long unsigned int same_char_counter = 1;
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

    string decode(string input) {
        if (input == "") {
            return "";
        }
        
        bool has_integers = false;
        string output = "";
        string integer_value = "";
        for (unsigned long int i = 0; i < input.size(); i++) {
            char current_char = input[i];
            if (current_char >= '0' && current_char <= '9') {
                has_integers = true;
                integer_value = integer_value + current_char;
                continue;
            }
            
            if (has_integers) {
                int no_of_chars = stoi(integer_value);
                for (int i=0; i<no_of_chars; i++) {
                    output = output + current_char;
                }
                integer_value = "";
                has_integers = false;
                no_of_chars = 0;
            } else {
                output = output + current_char;
            }
        }
        
        cout << "f output = " << output << endl;
        return output;
        
    }
}  // namespace run_length_encoding
