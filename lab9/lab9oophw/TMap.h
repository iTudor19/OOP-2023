#ifndef TMAP_H
#define TMAP_H

template <typename K, typename V>
class Map
{
private:
    struct Node
    {
        K key;
        V value;
        Node* next;
    };
    Node* head;
    int size;

public:
    Map();
    ~Map();
    void Set(const K& key, const V& value);
    bool Get(const K& key, V& value);
    int Count() const;
    void Clear();
    bool Delete(const K& key);
    bool Includes(const Map<K, V>& map) const;
    class Iterator;
    Iterator begin();
    Iterator end();
};

template <typename K, typename V>
class Map<K, V>::Iterator
{
private:
    Node* current;

public:
    Iterator(Node* n);
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    std::tuple<K, V, int> operator*() const;
};

#endif 