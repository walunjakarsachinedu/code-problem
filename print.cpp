#pragma once

#include<bits/stdc++.h>
using namespace std;


// ------------ declaration ------------

template<class T>
ostream& operator<<(ostream& out, const vector<T>& values);

template<class T>
ostream& operator<<(ostream& out, const set<T>& values);

template<class K, class V>
ostream& operator<<(ostream& out, const map<K, V>& values);

template<class K, class V>
ostream& operator<<(ostream& out, const pair<K,V>& value);

template<class K>
ostream& operator<<(ostream& out, stack<K> value);

template<class K>
ostream& operator<<(ostream& out, queue<K> values);

// ------------ implementation ------------

template<class T>
ostream& operator<<(ostream& out, const vector<T>& values) {
    out<<"[";
    for(auto value : values) out<<value<<", ";
    if(values.size()) out<<"\b\b";
    out<<"]";
    return out;
}
  
template<class T>
ostream& operator<<(ostream& out, const set<T>& values) {
    out<<"{";
    for(auto value : values) out<<value<<", ";
    if(values.size()) out<<"\b\b";
    out<<"}";
    return out;
}

template<class K, class V>
ostream& operator<<(ostream& out, const map<K, V>& values) {
    out<<"{";
    for(auto value : values) out<<value.first<<"="<<value.second<<", ";
    if(values.size()) out<<"\b\b";
    out<<"}";
    return out;
}

template<class K, class V>
ostream& operator<<(ostream& out, const pair<K,V>& value) {
    out<<"("<<value.first<<","<<value.second<<")";
    return out;
}

template<class K>
ostream& operator<<(ostream& out, stack<K> values) {
    cout<<"[";
    bool wasEmpty = values.empty();
    while(!values.empty()) {
        cout << values.top() << ", ";
        values.pop();
    }
    if(!wasEmpty) cout<<"\b\b";
    cout<<"]";
    return out;
}


template<class K>
ostream& operator<<(ostream& out, queue<K> values) {
    cout<<"[";
    bool wasEmpty = values.empty();
    while(!values.empty()) {
        out<<values.front()<<", "; 
        values.pop();
    }
    if(!wasEmpty) cout<<"\b\b";
    cout<<"]";
    return out;
}

template<typename V, typename _Sequence = vector<V>,
    typename _Compare  = less<typename _Sequence::value_type> >
ostream& operator<<(ostream& out, priority_queue<V, _Sequence, _Compare> values) {
    cout<<"[";
    bool wasEmpty = values.empty();
    while(!values.empty()) {
        cout<<values.top()<<", "; 
        values.pop();
    }
    if(!wasEmpty) cout<<"\b\b";
    cout<<"]";
    return out;
}
