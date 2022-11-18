#include <iostream>

//circular buffer implementation with array
template <class T>
class CBuffer
{
public:
    //constructor where you decide the size of buffer
    CBuffer(const int& );
    //default constuctor, makes a buffer of size 10
    CBuffer();
    ~CBuffer();
    //write to buffer head
    void write(const T& );
    //read from buffer tail
    T  read();
    //returns max capacity of buffer
    int getCapacity();
    //returns how many values are in buffer
    int getSize();
    //view a value from buffer from the order it was entered
    T& viewValue(const int& );
    void reset();
    //increase buffer size
    void increaseBuffer(const int& );

private:
    T * bufferArr;
    int capacity;
    int head;
    int tail;
    bool full;
};

template <class T> CBuffer<T>::CBuffer(const int &capacity)
{
    bufferArr = new T [capacity];
    this->capacity = capacity;
    this->head = 0;
    this->tail = 0;
    this->full = false;
}

template <class T> CBuffer<T>::CBuffer():CBuffer(10){}

template <class T> CBuffer<T>::~CBuffer()
{
    delete [] bufferArr;
}

template <class T> void CBuffer<T>::write(const T &value)
{
    if(this->full) throw std::runtime_error("buffer is full");
   
    this->bufferArr[this->head++] = value;
    //if it gets to the end of the array, go back to the beginning and write from there
    if(this->head == this->capacity) this->head = 0;
    if(this->head == this->tail) full = true;
    
}

template <class T> T CBuffer<T>::read()
{
    //check if buffer is empty
    if((this->head==this->tail)&& (this->full == false))
    {
        //throw exception that buffer is empty
        throw std::runtime_error("buffer is empty");
    }
    else
    {
        int temp = this->tail;
        //if it gets to the end of the array, go back to the beginning and read from there
        if(++this->tail == this->capacity) this->tail = 0;
        this->full = false;
        return bufferArr[temp];
    }
}

template <class T> int CBuffer<T>::getCapacity()
{
    return this->capacity;
}

template <class T> int CBuffer<T>::getSize()
{
    if (this->full == true) return this->capacity;
    else if (this->head >= this->tail) return (this->head - this->tail);
    else return (this->capacity - (this->tail - this->head));
}

template <class T> T& CBuffer<T>::viewValue(const int &pos)
{
    if(pos > getSize() || pos < 1)
    {
        std::cout << "number of elements in buffer is: " << this->getSize() << "\n";
        throw std::runtime_error("invalid postion entered");
    }
    if ((this->tail + pos -1) >= this->getCapacity()) return this->bufferArr[this->getCapacity() - (this->tail + pos-1)];
    else return this->bufferArr[this->tail + pos -1];

}

template <class T> void CBuffer<T>::reset()
{
    this->head = this->tail = 0;
    this->full = false;
}

template <class T> void CBuffer<T>::increaseBuffer(const int &addedLength)
{
    if(addedLength < 1)
    {
        std::cerr << "invalid input. you can only increace buffer by an interger greater than 0";
        return;
    }
    T * tempBufferArr = new T [this->capacity + addedLength];
    int tempTail = this->tail;
    int tempSize = this->getSize();
    for(int i = 0; i < tempSize; i++)
    {
        tempBufferArr[i++] = this->bufferArr[tempTail++];
        if(tempTail == this->capacity) tempTail = 0;
    }
    this->head = this->getSize();
    this->tail = 0;
    this->capacity += addedLength;
    delete [] this->bufferArr;
    this->bufferArr = tempBufferArr;
    this->full = false;
}
