
#include <stdio.h>

#define RANGE 65536

class TData {
public:
	bool IsEmpty;
	int Key;
	char Value[65];

	TData();
	void Print();

};

class TVector {
private:
	size_t capacity;
public:
	TData *array;
	size_t size;
	TVector();
	TVector(const size_t &);
	size_t Size() const;
	size_t Capacity() const;
	void Push_back(const TData &);
	void CountingSort(TVector* vector);
	~TVector();
};

TData::TData() {
	this->Key = 0;
}


void TData::Print() {
	printf("%d\t%s\n", this->Key, this->Value);
}

TVector::TVector() {
	size = 0;
	capacity = 1;
	array = new TData[capacity];
}

TVector::TVector(const size_t & sizeVector) {
	capacity = sizeVector;
	size = 0;
	array = new TData[sizeVector];
}

void TVector::Push_back(const TData &temp) {
	if (size == capacity) {
		capacity *= 2;
		TData *result = new TData[capacity];
		for (int index = 0; index < size; index++) {
			result[index] = array[index];
		}
		delete[] array;
		this->array = result;
	}
	array[size++] = temp;
}


size_t TVector::Size() const {
	return size;
}

size_t TVector::Capacity() const {
	return capacity;
}

void TVector::CountingSort(TVector* vector) {
	int tmp[RANGE] = { 0 };
	TData *out = new TData[vector->Size()];

	for (int i = 0; i < vector->Size(); i++) {
		tmp[vector->array[i].Key]++;
	}
	for (int i = 1; i < RANGE; i++) {
		tmp[i] += tmp[i - 1];
	}
	for (int i = vector->Size() - 1; i >= 0; i--) {
		out[--tmp[vector->array[i].Key]] = vector->array[i];
	}
	for (int i = 0; i < vector->Size(); ++i) {
		vector->array[i] = out[i];
	}
	delete[] out;
}



TVector::~TVector() {
	delete[] array;
}


int main(void) {

	TVector v;
	TData data;


	while (scanf("%d%s", &data.Key, data.Value) == 2) {
		v.Push_back(data);
	}

	if (v.Size() > 1) {
		v.CountingSort(&v);
	}
	for (int i = 0; i < v.Size(); ++i) {
		printf("%d\t%s\n", v.array[i].Key, v.array[i].Value);
	}

	return 0;
}