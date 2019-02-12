#ifndef ARRAY_H
#define ARRAY_H

//using namespace std;

#define MAX_SIZE  200

template <class T>
class Array
{
  public:
    Array();
    //~Array();

    void add(T*);
    int getSize();
    T* get(int);

  private:
    int    size;
    T* data[MAX_SIZE];
};

template <class T>
Array<T>::Array(){

  size = 0;
  qDebug("ARRAY CONSTRUCTOR CALLED");
}

//template <class T>
//Array<T>::~Array(){}

template <class T>
void Array<T>::add(T* i){
  qDebug("adsadsg ADDING BEFORE %d ", size);
  data[size] = i;
  qDebug("ADDING MIDDLE");
  size++;
  qDebug("ADDING AFTER");
}

template <class T>
int Array<T>::getSize(){
  return size;
}

template <class T>
T* Array<T>::get(int i){
  return data[i];
}


#endif
