//circular buffer implementation with linked list
#include <iostream>

template <class T>
struct Node
{
    Node * next;
    T value;
};
template <class T>
class CBufferLL
{
public:
    //constructor where you decide the size of buffer
    CBufferLL(const int& );
    //default constuctor, makes a buffer of size 10
    CBufferLL();
    ~CBufferLL();
    //write to buffer head
    void write(const T& );
    //read from buffer tail
    T read();
    //returns max capacity of buffer
    int getCapacity();
    //returns how many values are in buffer
    int getSize();
    //get a value from buffer from the order it was entered
    T& viewValue(int );
    //increase buffer size
    void increaseCapacity(int );
    void reset();
    
private:
    int capacity;
    Node <T>*head;
    Node <T>*tail;
};

template <class T> CBufferLL<T>::CBufferLL(const int& capacity)
{
    if(capacity < 1) throw std::runtime_error("constructor error: parameter must be an integer greater than 0");
    //NULL initialization of head and tail to show buffer is empty
    this->head = this->tail = NULL;
    this->capacity = capacity;
}

template <class T> CBufferLL<T>::CBufferLL():CBufferLL(10){}

template <class T> CBufferLL<T>::~CBufferLL()
{
    this->reset();
}
template <class T> void CBufferLL<T>::write(const T &value)
{
    if(getSize() == this->capacity) throw std::runtime_error("buffer is full");
    Node <T>* newNode = new Node<T>;
    if(this->head == NULL)
    {
        this->head->next = this->head = newNode;
        this->tail = this->head;
    }
    else
    {
        this->head->next = newNode;
        newNode->next = this->tail;
        this->head = newNode;
    }
    this->head->value = value;
}
template <class T> T CBufferLL<T>::read()
{
    if(this->head == NULL) throw std::runtime_error("buffer is empty");
    T temp = this->tail->value;
    
    if(this->tail != this->tail->next)
    {
        this->head->next = this->tail->next;
        delete this->tail;
        this->tail = this->head->next;
    }
    else
    {
        delete this->tail;
        this->head = this->tail = NULL;
    }
    return temp;
}
template <class T> int CBufferLL<T>::getCapacity()
{
    return this->capacity;
}
template <class T> int CBufferLL<T>::getSize()
{
    if(this->head == NULL) return 0;
    else
    {
        Node <T>* temp;
        temp = this->tail;
        int size = 1;
        while(temp->next != this->tail)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
}
template <class T> T& CBufferLL<T>::viewValue(int pos)
{
    if(pos > getSize() || pos < 1)
    {
        std::cout << "number of elements in buffer is: " << this->getSize() << "\n";
        throw std::runtime_error("invalid postion entered");
    }
    pos--;
    Node <T>* temp = this->tail;
    for(int i = 0 ; i < pos ; i ++)
    {
        temp = temp->next;
    }
    return temp->value;
}
template <class T> void CBufferLL<T>::increaseCapacity(int addedCapacity)
{
    if(addedCapacity < 1)
    {
        std::cout << "invalid input. you can only increace buffer by an interger greater than 0";
        return;
    }
    this->capacity +=addedCapacity;
}
template <class T> void CBufferLL<T>::reset()
{
    if(head != NULL)
    {
        Node<T>* temp = this->tail;
        while(this->tail != this->head)
        {
            this->tail = this->tail->next;
            delete temp;
            temp = this->tail;
        }
        delete this->head;
        this->head = this->tail = NULL;
    }
}