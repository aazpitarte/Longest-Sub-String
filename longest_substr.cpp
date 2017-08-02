#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>

int lengthOfLongestSubstring(std::string input) {
		
	// this array will map ascii value to the existence of a character
	bool char_map[256] = {0};
	
	int longest = 0;
	int cur_len = 0;
	int start = 0;	

	// loop through string
	int size = input.length();
	for (int i = 0; i < size; i++) {
		
		// if current character is not unique
		if (char_map[input[i]]) {	
			cur_len = 0;
			
			// zero out character map
			for (int j = 0; j < 300; j++) { char_map[j] = false; }
			
			// allows current character to start a new substring
			i = start;
			start++;
		}
		// if unique character
		else {
			char_map[input[i]] = true; // 
			cur_len++;
				
			//check if current substring is the longest
			if (cur_len > longest)
				longest = cur_len;
		}
			
	}
		
	return longest;
}

//=========================================================================
// Program Test Cases
//=========================================================================

TEST_CASE("No input") {
	
	REQUIRE( lengthOfLongestSubstring("") == 0 );

}

TEST_CASE("One unique character") {
	
	REQUIRE( lengthOfLongestSubstring("a") == 1 );
	REQUIRE( lengthOfLongestSubstring("1") == 1 );
	REQUIRE( lengthOfLongestSubstring(";") == 1 );
	
}


TEST_CASE("All unique characters") {
	
	REQUIRE( lengthOfLongestSubstring("qwertyuiop") == 10 );
	REQUIRE( lengthOfLongestSubstring("asdf") == 4 );
	REQUIRE( lengthOfLongestSubstring("123456789") == 9 );
	
}

TEST_CASE("All repeating characters") {
	
	REQUIRE( lengthOfLongestSubstring("aaaaaaaaaaaaa") == 1 );
	REQUIRE( lengthOfLongestSubstring("           ") == 1 );
	REQUIRE( lengthOfLongestSubstring(".........") == 1 );
	
}

