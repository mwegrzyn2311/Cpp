#ifndef LAB6_MYSTRING_HPP
#define LAB6_MYSTRING_HPP

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <functional>

class MyString {
public:
	static constexpr size_t initialBufferSize = 20;
	static constexpr char charset[] =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
private:
	char values[initialBufferSize]{};
	std::string additionalValues;
	size_t currSize = 0;
public:
	MyString();
	MyString(const char* text);
	MyString(const std::string& text);

	[[nodiscard]] size_t size() const;
	[[nodiscard]] size_t capacity() const;
	[[nodiscard]] bool empty() const;
	void clear();
	void trim();
	friend std::ostream& operator<<(std::ostream& out, const MyString& myString);
	friend std::istringstream& operator>>(std::istringstream& in, MyString& myString);
	MyString& operator+=(char character);
	MyString& operator+=(const MyString& other);
	const char& operator[](size_t index) const;
	char& operator[](size_t index);
	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;
	bool operator<(const MyString& other) const;
	bool operator>(const MyString& other) const;
	bool operator<=(const MyString& other) const;
	bool operator>=(const MyString& other) const;
	[[nodiscard]] std::set<MyString> getUniqueWords() const;
	[[nodiscard]] std::map<MyString, size_t> countWordsUsage() const;
	void toLower();
	static MyString generateRandomWord(size_t wordLength);
	[[nodiscard]] bool startsWith(const std::string& word) const;
	[[nodiscard]] bool endsWith(const std::string& word) const;
	[[nodiscard]] MyString join(const std::vector<MyString>& strings) const;
	bool all_of(const std::function<int(int)>& fn) const;
	void push_back(char c)  {*this += c;}

	/** Iterator */
	struct Iterator {
		typedef Iterator self_type;
		typedef char value_type;
		typedef char& reference;
		typedef char* pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef int difference_type;

		MyString* myString;
		size_t index;
	public:
		explicit Iterator(MyString& myString, int index): myString(&myString), index(index) { }

		reference operator*() const {
			return (*myString)[index];
		}
		pointer operator->() const {
			return &(*myString)[index];
		}
		self_type& operator++() {
			++index;
			return *this;
		}
		self_type operator++(int) {
			auto res = *this;
			++index;
			return res;
		}
		self_type& operator--() {
			index--;
			return *this;
		}
		self_type operator--(int) {
			auto res = *this;
			index--;
			return res;
		}
		difference_type operator-(const Iterator& other) {
			return this->index - other.index;
		}
		bool operator==(const Iterator& other) const { return this->index == other.index; }
		bool operator!=(const Iterator& other) const { return this->index != other.index; }

		friend class MyString;
	};
	/** Const iterator */
	struct ConstIterator {
		typedef ConstIterator self_type;
		typedef const char value_type;
		typedef const char& reference;
		typedef const char* pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef int difference_type;

		const MyString* myString;
		size_t index;
	public:
		explicit ConstIterator(const MyString& myString, int index): myString(&myString), index(index) { }
		reference operator*() const {
			return (*myString)[index];
		}
		pointer operator->() const {
			return &(*myString)[index];
		}
		self_type& operator++() {
			index++;
			return *this;
		}
		self_type operator++(int) {
			auto res = *this;
			index++;
			return res;
		}
		self_type& operator--() {
			index--;
			return *this;
		}
		self_type operator--(int) {
			auto res = *this;
			index--;
			return res;
		}
		difference_type operator-(const ConstIterator& other) {
			return this->index - other.index;
		}
		bool operator==(const ConstIterator& other) const { return this->index == other.index; }
		bool operator!=(const ConstIterator& other) const { return this->index != other.index; }

		friend class MyString;
	};
	//Traits
public:
	typedef char value_type;
	typedef Iterator iterator;
	typedef ConstIterator const_iterator;
	typedef std::reverse_iterator<Iterator> reverse_iterator;
	typedef std::reverse_iterator<ConstIterator> const_reverse_iterator;

	iterator begin() { return Iterator(*this, 0); }
	iterator end() { return Iterator(*this, size()); }
	[[nodiscard]] const_iterator begin() const { return ConstIterator(*this, 0); }
	[[nodiscard]] const_iterator end() const { return ConstIterator(*this, size()); }
	reverse_iterator rbegin() { return std::reverse_iterator(Iterator(*this, (int)size())); }
	reverse_iterator rend() { return std::reverse_iterator(Iterator(*this, 0)); }
	[[nodiscard]] const_reverse_iterator rbegin() const { return std::reverse_iterator(ConstIterator(*this, (int)size())); }
	[[nodiscard]] const_reverse_iterator rend() const { return std::reverse_iterator(ConstIterator(*this, 0)); }

	[[nodiscard]] MyString getNextWord(ConstIterator& it) const;
	[[nodiscard]] MyString getNextWordCaseSensitive(ConstIterator& it) const;
};


#endif //LAB6_MYSTRING_HPP
