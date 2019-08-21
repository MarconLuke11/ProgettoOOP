#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>

//compilazione per inclusione del template

template <class T>
class Container;

template <class T>
std::ostream& operator<<(std::ostream&, const Container<T>&);

template <class T>
class Container
{
      friend std::ostream& operator<< <T> (std::ostream&, const Container&);
public:
      class iteratore;
      class const_iteratore;
private:
      class nodo {
      public:
        T info;
        nodo *prev,*next;
        nodo(const T&, nodo* p=0, nodo* n=0);
        ~nodo();
      };
      static nodo* copy(nodo*, nodo*&);
      static std::ostream& print(nodo*, std::ostream&);
      nodo *first, *last;

public:

      class iteratore{
          friend class Container<T>;
      private:
          nodo* it;
          bool pastEnd;  // restituisce true se sono dopo end, cioe' se sono in past-the-end
      public:
          iteratore(nodo* =0, bool =false);
          iteratore& operator++();
          iteratore operator++(int);
          iteratore& operator--();
          iteratore operator--(int);
          T& operator*() const;
          T* operator->() const;
          bool operator==(const iteratore&) const;
          bool operator!=(const iteratore&) const;
      };

      class const_iteratore{
          friend class Container<T>;
      private:
          const nodo* cit;
          bool pastEnd;  // restituisce true se sono dopo end, cioe' se sono in past-the-end
      public:
          const_iteratore(const nodo* =0, bool =false);
          const_iteratore& operator++();
          const_iteratore operator++(int);
          const_iteratore& operator--();
          const_iteratore operator--(int);
          const T& operator*() const;
          const T* operator->() const;
          bool operator==(const const_iteratore&) const;
          bool operator!=(const const_iteratore&) const;
      };

      Container();
      Container(const Container<T>&);
      Container& operator=(const Container<T>&);
      ~Container();
      bool empty() const;
      void push_back(const T&);
      void pop_back();
      void push_front(const T&);
      void pop_front();
      iteratore begin() const;
      iteratore end() const;
      iteratore min_element(iteratore, iteratore) const;
      const_iteratore cbegin() const;
      const_iteratore cend() const;
      // iteratore search(const T&) const;
      void remove(int);
      void removeAlt();
      int count() const;
      void swap(T&, T&);
      int size() const;
      iteratore getItem(int i) const;
};



//classe nodo
template<class T>
Container<T>::nodo::nodo(const T& t, nodo* p, nodo* n): info(t), prev(p), next(n) {}

template<class T>
Container<T>::nodo::~nodo()
{
    if(next) delete next;
}

//metodi statici
template<class T>
typename Container<T>::nodo* Container<T>::copy(nodo* fst,nodo*& lst)
{
    if(fst == nullptr) return lst = nullptr;
    nodo* f = new nodo(fst->info,nullptr,nullptr), *p = f;
    while(fst->next != nullptr) {
         p->next = new nodo(fst->next->info,p,nullptr);
         fst = fst->next;
         p=p->next;
    }
    lst=p;
    return f;
}

template<class T>
typename std::ostream& Container<T>::print(nodo* l,std::ostream& os)
{
    if(!l) return os;
    os << l->info << ' ';
    print(l->next,os);
    return os;
}

//classe iteratore
template<class T>
Container<T>::iteratore::iteratore(nodo* n, bool past):it(n), pastEnd(past){}

template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++()
{ //incremento prefisso
    if(!pastEnd && it){
        if(it->next)
            it = it->next;
        else{
            it = it+1;
            pastEnd = true;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::iteratore Container<T>::iteratore::operator++(int)
{ //incremento postfisso
    if(!pastEnd && it){
        if(it->next)
            it= it->next;
        else{
            it = it+1;
            pastEnd = true;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator--()
{ //decremento prefisso
    if(pastEnd){
        it = it-1;
        pastEnd = false;
    }
    else
        if(it)
            it = it->prev;
    return *this;
}

template<class T>
typename Container<T>::iteratore Container<T>::iteratore::operator--(int)
{ //decremento postfisso
    if(pastEnd){
        it = it-1;
        pastEnd = false;
    }
    else
        if(it)
            it = it->prev;
    return *this;
}

template<class T>
T& Container<T>::iteratore::operator*() const
{
    return it->info;
}

template<class T>
T* Container<T>::iteratore::operator->() const
{
    return &(it->info);
}

template<class T>
bool Container<T>::iteratore::operator==(const iteratore& i) const
{
    return it==i.it;
}

template<class T>
bool Container<T>::iteratore::operator!=(const iteratore& i) const
{
    return it!=i.it;
}

//classe constiteratore
template<class T>
Container<T>::const_iteratore::const_iteratore(const nodo* n, bool past):cit(n), pastEnd(past){}

template<class T>
typename Container<T>::const_iteratore& Container<T>::const_iteratore::operator++()
{ //incremento prefisso
    if(!pastEnd && cit){
        if(cit->next)
            cit = cit->next;
        else{
            cit = cit+1;
            pastEnd = true;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::const_iteratore Container<T>::const_iteratore::operator++(int)
{ //incremento postfisso
    if(!pastEnd && cit){
        if(cit->next)
            cit = cit->next;
        else{
            cit= cit+1;
            pastEnd = true;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::const_iteratore& Container<T>::const_iteratore::operator--()
{ //decremento prefisso
    if(pastEnd){
        cit = cit-1;
        pastEnd = false;
    }
    else
        if(cit)
            cit = cit->prev;
    return *this;
}

template<class T>
typename Container<T>::const_iteratore Container<T>::const_iteratore::operator--(int)
{ //decremento postfisso
    if(pastEnd){
        cit = cit-1;
        pastEnd = false;
    }
    else
        if(cit)
            cit = cit->prev;
    return *this;
}

template<class T>
const T& Container<T>::const_iteratore::operator*() const
{
    return (cit->info);
}

template<class T>
const T* Container<T>::const_iteratore::operator->() const
{
    return &(cit->info);
}

template<class T>
bool Container<T>::const_iteratore::operator==(const const_iteratore& i) const
{
    return cit==i.cit;
}

template<class T>
bool Container<T>::const_iteratore::operator!=(const const_iteratore& i) const
{
    return cit!=i.cit;
}

//classe container
template<class T>
Container<T>::Container():first(nullptr), last(nullptr){}

template<class T>
Container<T>::Container(const Container<T>& c)
{
     first = copy(c.first,last);
}

template<class T>
Container<T>& Container<T>::operator= (const Container<T>& c)
{
    if(this != &c) {
          if(first) delete first;
          first=copy(c.first,last);
        }
    return *this;
}

template<class T>
Container<T>::~Container()
{
     if (first) delete first;
}

template<class T>
bool Container<T>::empty() const
{
    return !first && !last;
}

template<class T>
void Container<T>::push_back(const T& t)
{ //aggiunge in coda l'elemento t
    last = new nodo(t,last,nullptr);
    if(first == nullptr)
        {first = last;}
    else {
        (last->prev)->next = last;
    }
}

template<class T>
void Container<T>::pop_back()
{ //rimuove (se c'è) l'elemento in coda
    if(last){
        if(last->prev){
            nodo* tmp = last;
            last = last->prev;
            last->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
        }
        else{
            delete first;
            first = nullptr;
            last = nullptr;
        }
    }
}

template<class T>
void Container<T>::push_front(const T& t)
{ //aggiunge in testa l'elemento t
    first = new nodo(t,nullptr,first);
    if(last == nullptr)
        {last = first;}
    else {
        (first->next)->prev = first;
    }
}

template<class T>
void Container<T>::pop_front()
{ //rimuove (se c'è) l'elemento in testa
    if(first){
        if(first->next){
            nodo* tmp = first;
            first = first->next;
            first->prev = nullptr;
            tmp->next = nullptr;
            delete tmp;
        }
        else{
            delete first;
            first = nullptr;
            last = nullptr;
        }
    }
}

template<class T>
typename Container<T>::iteratore Container<T>::begin() const
{
    return iteratore(first);
}

template<class T>
typename Container<T>::iteratore Container<T>::end() const
{
    if(first == nullptr)
        return iteratore(nullptr);
    return iteratore(last+1);
}

template<class T>
typename Container<T>::iteratore Container<T>::min_element(iteratore begin, iteratore end) const
{
    iteratore min = begin;
    for(iteratore it = begin; it != end; it++)
    {
        if(**it < **min)
            min = it;
    }
    return min;
}

template<class T>
typename Container<T>::const_iteratore Container<T>::cbegin() const
{
    return const_iteratore(first);
}

template<class T>
typename Container<T>::const_iteratore Container<T>::cend() const
{
    if(first == nullptr)
        return const_iteratore(nullptr);
    return const_iteratore(last+1);
}

template <class T>
void Container<T>::remove(int i)
{
    iteratore iter= getItem(i);
    if (iter.it)
    {
        if (!iter.it->prev && !iter.it->next)
        {
            delete iter.it;
            first=last=0;
            return;
        }
        if (!iter.it->prev && iter.it->next)
        {
            pop_front();
            return;
        }
        if (iter.it->prev && !iter.it->next)
        {
            pop_back();
            return;
        }
        nodo* tmp = iter.it;
        iter.it->prev->next = iter.it->next;
        iter.it->next->prev = iter.it->prev;
        tmp->prev = tmp->next = nullptr;
        delete tmp;
    }
}

template <class T>
void Container<T>::removeAlt()
{
    while (begin()!=end()){
        pop_front();
    }
}

template <class T>
int Container<T>::count() const
{
    int cont=0;
    const_iteratore iter=cbegin();
    for (;iter!=cend();iter++){
        cont++;
    }
    return cont;
}

template <class T>
void Container<T>::swap(T& t1,T& t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

template <class T>
int Container<T>::size() const
{
    int count = 0;
    for(auto cit = cbegin(); cit != cend(); cit++)
        count++;
    return count;
}

template <class T>
typename Container<T>::iteratore Container<T>::getItem(int i) const
{
    int indice = 0;

    iteratore it = begin();
    while(indice<i){
        indice++;
        it++;
    }
    return it;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& q)
{
    return Container<T>::print(q.first,os);
}

#endif // CONTAINER_H
