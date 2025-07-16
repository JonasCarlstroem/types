#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <functional>
#include <vector>

using string = std::string;

template<class TKey, class TValue>
using dictionary = std::map<TKey, TValue>;

template<class T>
using list = std::vector<T>;

using string_map = std::map<string, string>;

template<typename T>
struct ref {
    T* ptr;
    ref(T& obj) : ptr(&obj) {}
    T& get() { return *ptr; }
    operator T& () { return *ptr; }
};

template<typename T>
ref<T> make_ref(const T& obj) {
    return ref(const_cast<T&>(obj));
}

template<typename T>
ref<T> make_ref(T&& obj) {
    return ref(obj);
}