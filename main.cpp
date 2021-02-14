#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <string>
#include <vector>

std::vector<std::string> loadWords(std::string path);
std::size_t random_range(int min, std::size_t max);
int main() {

	std::string filename = "words.txt";
	std::vector<std::string> words = loadWords(filename);

	std::string word = words.at(random_range(0, words.size()));
	std::cout << word << std::endl;
	int lives = word.length();
	int word_length = word.length();
	std::vector<char> wrongGuesses, foundCharacters;
	char guess;

	for (int i = 0; i < word_length; ++i) {
		foundCharacters.push_back('*');
	}
	int playing = 1;
	int correctGuesses = 0;
	while (playing) {
		std::cout << "Lives: ";
		for (int i = 0; i < lives; ++i) {
			std::cout << "♥ ";
		}
		std::cout << "\nWord: ";
		for (auto c : foundCharacters) {
			std::cout << c;
		}
		std::cout << "\nWrong guesses: |";
		for (auto c : wrongGuesses) {
			std::cout << c << "|";
		}
		std::cout << "\nEnter a character: ";
		std::cin >> guess;
		int found = 0;
		for (int i = 0; i < word_length; ++i) {
			if (guess == word[i]) {
				found = 1;
				foundCharacters[i] = guess;
				++correctGuesses;
			}
		}
		if (found == 0) {
			wrongGuesses.push_back(guess);
			--lives;
		}
		if (lives == 0) {
			std::cout << "You lost!\nThe correct word was: <" << word << ">.\n";
			playing = 0;
		} else if (correctGuesses == word_length) {
			std::cout << "Congratulations!\nYou found the word!\n";
			playing = 0;
		}
	}
}

std::vector<std::string> loadWords(std::string path) {
	// open the text file and read all the words into a vector
	std::vector<std::string> words;
	std::ifstream file;
	file.open(path);
	if (!file.is_open()) {
		std::cout << "failed to open " << path << '\n';
	} else {
		std::string word;
		while (file >> word) {
			words.push_back(word);
		}
	}
	return words;
}
std::size_t random_range(int min, std::size_t max) {
	static std::default_random_engine eng(std::random_device{}());
	std::uniform_int_distribution<std::size_t> dist(min, max);
	return dist(eng);
}
