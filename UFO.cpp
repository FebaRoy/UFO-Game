#include <iostream>
#include <vector>
#include <ctime>
#include "ufo_functions.hpp"

int main() {

  char play_again;
  std::cout<<"Enter you name: ";
  std::string Name;
  std::cin>>Name;
  greetings(Name);

  do
  {
    srand(time(NULL));

    std::vector<std::string> codewords = {"codecademy", "school", "nintendo", "coding", "programming", "cplusplus"};
    std::string codeword = codewords[rand() % codewords.size()];
    std::string answer;
    int misses = 0;

    std::vector<char> incorrect;
    bool guess = false;

    char letter;
    

    for (int l = 0; l < codeword.size(); l++)
    {
      answer += "_";
    }

    while (answer != codeword && misses < 7)
    {
      display_misses(misses);

      display_status(incorrect, answer);

      std::cout << "\n\nPlease enter your guess: ";
      std::cin >> letter;
      letter = tolower(letter);

      for (int k = 0; k < codeword.size(); k++)
      {
        if (letter == codeword[k])
        {
          answer[k] = letter;
          guess = true;
        }
      }

      if (guess)
      {
        std::cout << "Correct!\n\n";
      }
      else
      {
        std::cout << "Incorrect! The tractor beam pulls the person in further.\n\n";
        incorrect.push_back(letter);
        misses++;
      }
      
      guess = false;
      
    }

    end_game(answer, codeword);

    std::cout << "Would you like to play again?\n\nType y for yes and n for no\n\n";
    std::cin >> play_again;
    play_again = tolower(play_again);
    std::cout << "\n\n";
  } while(play_again == 'y');

  
}