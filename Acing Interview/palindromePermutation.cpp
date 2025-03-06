/*
 
 * Given a string, write a function to check if it is a permutation of a pallindrome.
 *
 * Solution Philosophy:
 * For a string to be pallindrome, it should be able to spelled backward and forward the same.
 * Therefore the chars in string should fit one of the two possibilities:
 *  - Each char appear even number of times in the string ( even length string )
 *  - Each char should appear even number of times, except just one char ( odd length string )
 * 
 * We won't care about the case of the letter
 */

 #include <iostream>


 /*
  * Helper routine to return an frequency Table index
  *
  */
 
 int getCharIndex( char c )
 {
     int idx = -1;
     if ( c >= 'a' && c <= 'z' )
     {
         idx = c - 'a';
     }
     else if ( c >= 'A' && c <= 'Z' )
     {
         idx = c - 'A';
     }
     return idx;
 }
 
 /*
  * Function : countFrequency
  * Args     : input string, an array of int 
  * Return   : Void, array of int will populate each letter's frequency in string.
  */
 
 void countFrequency( const std::string & str, int *frequency )
 {
     int idx;
     for (const char & c : str)
     {
         idx = getCharIndex(c);
         if ( idx != -1 )
         {
             ++frequency[idx];
         }
     }
 }
 
 
 /*
  * Function : isPermutePallindrome 
  * Args     : input string
  * Return   : returns true if is possible that one of the permutations of input string can be a pallindrome.
  *            else return false
  */
 
 bool isPermutationOfPallindrome1( const std::string & str )
 {
     int frequency[ 26 ] = { 0 };
     countFrequency( str, frequency );
 
     /*
      * We will check here that letter frequencies are all even or all even except one odd.
      */
     bool oddAppeared = false;
     std::cout << std::endl;
     for ( int i = 0 ; i < 26; ++i ) {
         if ( frequency[i] % 2  && oddAppeared ) {
             return false;
         } else if ( frequency[i] % 2 && !oddAppeared ) {
             oddAppeared = true;
         }
     }
     return true;
 }
 
 
 /*
  * Approach 2:
  * Let us optimize above function instead of taking another pass let us do it
  * in one go, we will count odd chars as we go along, if we are left with 
  * more that 0 or 1, then the input string can't have pallindrome permutation
  */
 
 bool isPermutationOfPallindrome2( const std::string & str )
 {
     int oddCount = 0;
     int frequency[26] = { 0 };
     int idx = 0;
     for ( const char & c : str )
     {
         idx = getCharIndex(c);
         if ( idx != -1 )
         {
             ++frequency[idx];
             if ( frequency[idx] % 2 ) 
             {   
                 ++oddCount;
             } else {
                 --oddCount;
             }
         }
     }
     return (oddCount <= 1);
 }