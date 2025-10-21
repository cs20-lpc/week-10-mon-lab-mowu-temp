template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::numComps = 0;

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(int i)
: list(new ArrayList<Record>(i)) { }

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(const ArrayListDictionary<Key, Val>& copyObj) {
    copy(copyObj);
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>& ArrayListDictionary<Key, Val>::operator=(const ArrayListDictionary<Key, Val>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::~ArrayListDictionary() {
    delete list;
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchIter(const Key& target, int left, int right) const {
    while (left < right) {
        int middle = (left + right) / 2;
        Record rec = list->getElement(middle);
        numComps++;
        if (target == rec.k) {
            return rec.v;
        } else if (target > rec.k) {
            left = middle + 1;
        } else if (target < rec.k) {
            right = middle - 1;
        }
    }
    if (left > right) {
        throw string("key not found");
    }
    if (left == right) {
        Record rec = list->getElement(left);
        numComps++;
        if (rec.k == target) {
            return rec.v;
        } else {
            throw string("key not found");
        }
    }
    throw string("what");
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::binSearchRec(const Key& target, int left, int right) const {
    if (left > right) {
        throw string("key not found");
    }
    if (left == right) {
        Record rec = list->getElement(left);
        numComps++;
        if (rec.k == target) {
            return rec.v;
        } else {
            throw string("key not found");
        }
    }
    int middle = (left + right) / 2;
    Record rec = list->getElement(middle);
    numComps++;
    if (target == rec.k) {
        return rec.v;
    } else if (target > rec.k) {
        return binSearchRec(target, middle+1, right);
    } else if (target < rec.k) {
        return binSearchRec(target, left, middle-1);
    }
    throw string("what");

}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::copy(const ArrayListDictionary<Key, Val>& copyObj) {
    list = new ArrayList<Record>(*copyObj.list);
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::find(const Key& k) const {
    numComps = 0;

    try {

        // int ans = seqSearchIter(k);
        // int ans2 = seqSearchRec(k);
        // if (ans2 != ans) {
        //     std::cout << "BAD BAD BAD" << std::endl;
        // }
        // ans2 = binSearchIter(k, 0, list->getLength() - 1);
        // if (ans2 != ans) {
        //     std::cout << "BAD BAD BAD" << std::endl;
        // }
        // ans2 = binSearchRec(k, 0, list->getLength() - 1);
        // if (ans2 != ans) {
        //     std::cout << "BAD BAD BAD" << std::endl;
        // }
        // return ans;


        // return seqSearchIter(k);
        // return seqSearchRec(k);
        // return binSearchIter(k, 0, list->getLength() - 1);
        return binSearchRec(k, 0, list->getLength() - 1);
    }
    catch (...) {
        throw string("find: error, unsuccessful search, target key not found");
    }
}

template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::getNumComps() {
    return numComps;
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::remove(const Key& k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        throw string("remove: error, unable to find record with matching key to remove");
    }
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchIter(const Key& target) const {
    for (int i = 0; i < list->getLength(); i++) {
        Record rec = list->getElement(i);
        numComps++;
        if (rec.k == target) {
            return rec.v;
        }
    }
    throw string("key not found");
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::seqSearchRec(const Key& target, int i) const {
    if (i >= list->getLength()) {
        throw string("key not found");
    }
    Record rec = list->getElement(i);
    numComps++;
    if (rec.k == target) {
        return rec.v;
    }
    return seqSearchRec(target, i+1);
    throw string("key not found");
}

template <typename Key, typename Val>
int ArrayListDictionary<Key, Val>::size() const {
    return list->getLength();
}
