#include "vector.h"
#include <memory>
using namespace std;

Vector::Vector(size_t initialCapacity):
    dataSize(0),
    dataCapacity(initialCapacity),
    data(make_unique<Fraction[]>(dataCapacity)){ }

size_t Vector::size() const {
    return this->dataSize;
}
size_t Vector::capacity() const {
    return this->dataCapacity;
}

Vector::Vector(const Vector& vector):
    dataSize(vector.dataSize),
    dataCapacity(vector.dataCapacity),
    data(make_unique<Fraction[]>(this->dataCapacity)) {
    copy(vector.data.get(), vector.data.get()+vector.dataSize, this->data.get());
}

Vector::Vector(Vector&& vector) noexcept:
    dataSize(vector.dataSize),
    dataCapacity(vector.dataCapacity),
    data(move(vector.data)){
    vector.dataSize = 0;
    vector.dataCapacity = 0;
}

void Vector::push_back(const Fraction& fraction) {
    if(this->dataSize == this->dataCapacity) {
        this->dataCapacity++;
        unique_ptr<Fraction[]> tmp = make_unique<Fraction[]>(this->dataCapacity);
        for(size_t i = 0; i < this->dataSize; i++) {
            tmp[i] = this->data[i];
        }
        this->data = move(tmp);
    }
    this->data[this->dataSize++] = fraction;
}
const Fraction Vector::operator[](size_t index) const{
    if(index >= this->dataSize)
        throw out_of_range("Cannot access element from index out of bounds");
    return this->data[index];
}


Vector& Vector::operator=(const Vector& vector) {
    if(this == &vector)
        return *this;
    if(this->dataCapacity != vector.dataCapacity) {
        this->dataCapacity = vector.dataCapacity;
        this->data.reset();
        this->data = make_unique<Fraction[]>(this->dataCapacity);
    }
    this->dataSize = vector.dataSize;
    copy(vector.data.get(), vector.data.get() + vector.dataSize,this->data.get());
    return *this;
}
Vector& Vector::operator=(Vector&& vector) noexcept{
    if(this == &vector) {
        return *this;
    }
    this->dataCapacity = vector.dataCapacity;
    this->dataSize = vector.dataSize;
    vector.dataCapacity =0;
    vector.dataSize = 0;
    this->data = move(vector.data);
    return *this;
}
