#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iterator>
#include "MyString.hpp"

MyString::MyString(): additionalValues({}) {
	additionalValues.clear();
}
MyString::MyString(const char* text): additionalValues({}), currSize(strlen(text)) {
	additionalValues.clear();
	size_t i;
	for(i = 0; i < initialBufferSize && i < strlen(text); ++i) {
		values[i] = text[i];
	}
	if(i >= initialBufferSize) {
		additionalValues.reserve(strlen(text)-i);
		for(; i < strlen(text); ++i) {
			additionalValues.push_back(text[i]);
		}
	}
}
MyString::MyString(const std::string& text): additionalValues({}), currSize(text.length()) {
	additionalValues.clear();
	size_t i;
	for(i = 0; i < 20 && i < text.length(); ++i) {
		values[i] = text[i];
	}
	if(i >= initialBufferSize) {
		additionalValues.reserve(text.length()-i);
		additionalValues += text.substr(initialBufferSize);
	}
}

size_t MyString::size() const {
	return currSize;
}

size_t MyString::capacity() const {
	return initialBufferSize + additionalValues.capacity();
}
bool MyString::empty() const {
	return currSize == 0;
}

void MyString::clear() {
	values[0] = '\0';
	additionalValues.clear();
	currSize = 0;
}

void MyString::trim() {
	auto it = std::find_if_not(begin(), end(), ::isspace);
	auto itReverse = std::find_if_not(rbegin(), rend(), ::isspace);
	std::string tmp;
	tmp.resize(std::distance(it, itReverse.base()));
	std::copy(it, itReverse.base(), tmp.begin());
	*this = tmp;
}
std::ostream& operator<<(std::ostream& out, const MyString& myString) {
	for(char it : myString) {
		out<<it;
	}
	return out;
}
std::istringstream& operator>>(std::istringstream& in, MyString& myString) {
	myString = in.str();
	return in;
}

MyString& MyString::operator+=(char character) {
	if(size() < initialBufferSize) {
		values[size()] = character;
	} else {
		additionalValues.push_back(character);
	}
	++currSize;
	return *this;
}
MyString& MyString::operator+=(const MyString& other) {
	if(size() < initialBufferSize) {
		size_t i = currSize;
		size_t j = 0;
		for(; j < initialBufferSize && j < other.size(); ++j) {
			if(i < initialBufferSize) {
				values[i++] = other[j];
			} else {
				additionalValues.push_back(other[j]);
			}
		}
	} else {
		additionalValues += other.values;
	}
	additionalValues += other.additionalValues;
	currSize += other.currSize;
	return *this;
}

const char& MyString::operator[](size_t index) const {
	if(index >= size()) {
		throw std::out_of_range("Trying to access uninitialized character from MyString");
	}
	if (index < initialBufferSize) {
		return values[index];
	} else {
		return additionalValues[index - initialBufferSize];
	}
}

char& MyString::operator[](size_t index) {
	if(index >= size()) {
		throw std::out_of_range("Trying to access uninitialized character from MyString");
	}
	if (index < initialBufferSize) {
		return values[index];
	} else {
		return additionalValues[index - initialBufferSize];
	}
}

bool MyString::operator==(const MyString& other) const {
	size_t size1 = size();
	size_t size2 = other.size();
	if(size1 != size2) {
		return false;
	}
	auto it = std::mismatch(begin(), end(), other.begin());
	return (it.first == end());
}
bool MyString::operator!=(const MyString& other) const {
	return !(*this == other);
}
bool MyString::operator<(const MyString& other) const {
	auto it = std::mismatch(begin(), end(), other.begin(), other.end());
	if(it.first == end()) {
		return false;
	} else if(it.second == other.end()) {
		return true;
	}
	return (*it.first < *it.second);
}
bool MyString::operator>(const MyString& other) const {
	return (!(*this == other) && ! (*this < other));
}
bool MyString::operator<=(const MyString& other) const {
	return !(*this > other);
}
bool MyString::operator>=(const MyString& other) const {
	return !(*this < other);
}

MyString MyString::getNextWord(ConstIterator& it) const {
	auto spaceIt = std::find_if(it, end(), ::isalpha);
	std::advance(it, std::distance(it, spaceIt));
	MyString res;
	std::transform(it, std::find_if_not(it, end(), ::isalpha), std::back_inserter(res),
			::tolower);
	std::advance(it, res.size());
	return res;
}
std::set<MyString> MyString::getUniqueWords() const {
	std::set<MyString> res;
	auto it = begin();
	MyString tmp = getNextWord(it);
	while(it!=end()) {
		res.emplace(tmp);
		tmp = getNextWord(it);
	}
	return res;
}

MyString MyString::getNextWordCaseSensitive(ConstIterator& it) const {
	auto spaceIt = std::find_if(it, end(), ::isalpha);
	std::advance(it, std::distance(it, spaceIt));
	MyString res;
	std::copy(it, std::find_if_not(it, end(), ::isalpha), std::back_inserter(res));
	std::advance(it, res.size());
	return res;
}
std::map<MyString, size_t> MyString::countWordsUsage() const {
	std::map<MyString, size_t> res;
	auto it = begin();
	while(it!=end()) {
		MyString tmp = getNextWordCaseSensitive(it);
		++res[tmp];
	}
	return res;
}

void MyString::toLower() {
	std::transform(begin(), end(), begin(), ::tolower);
}
char randomChar() {
	return MyString::charset[rand()%52];
}
MyString MyString::generateRandomWord(size_t wordLength) {
	srand(time(nullptr));
	MyString res;
	std::generate_n(std::back_inserter(res), wordLength, randomChar);
	return res;
}

bool MyString::startsWith(const std::string& word) const {
	auto it = std::search(begin(), end(), word.begin(), word.end());
	return (it == begin());
}
bool MyString::endsWith(const std::string& word) const {
	auto it = std::search(rbegin(), rend(), word.rbegin(), word.rend());
	return (it.base() == end());
}

MyString MyString::join(const std::vector<MyString>& strings) const {
	auto it = strings.begin();
	MyString res(*it++);
	for(; it != strings.end(); ++it) {
		res += *this;
		res += *it;
	}
	return res;
}

bool MyString::all_of(const std::function<int(int)>& fn) const {
	return std::all_of(begin(), end(), fn);
}
