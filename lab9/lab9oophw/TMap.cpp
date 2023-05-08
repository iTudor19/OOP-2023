#include "TMap.h"
#include <iostream>

template <typename K, typename V>
TMap<K, V>::TMap() {
    head = nullptr;
    size = 0;
}

template <typename K, typename V>
void TMap<K, V>::Set(const K& key, const V& value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Node* newNode = new Node{ key, value, head };
    head = newNode;
    size++;
}

template <typename K, typename V>
bool TMap<K, V>::Get(const K& key, V& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename K, typename V>
int TMap<K, V>::Count() const {
    return size;
}

template <typename K, typename V>
void TMap<K, V>::Clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}
    
template <typename K, typename V>
bool TMap<K, V>::Delete(const K& key) {
    if (count == 0) {
        return false;
    }
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <typename K, typename V>
bool TMap<K, V>::Includes(const TMap<K, V>& map) const {
    Node* current = map.head;
    while (current != nullptr) {
        V value;
        if (!Get(current->key, value) || value != current->value) {
            return false;
        }
        current = current;
    }
}
