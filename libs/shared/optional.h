#pragma once
#include <assert.h>

template <typename T>
struct Optional {
public:
    Optional() = default;
    Optional(const T& value) : _value(value), _set(true) {}

    [[nodiscard]] bool has_value() const { return _set; }

    [[nodiscard]] T& value() {
        assert(_set);
        return _value;
    }

    [[nodiscard]] const T& value() const {
        assert(_set);
        return _value;
    }

    T* operator->() {
        return &value();
    }

    [[nodiscard]] T& raw_value() { return _value; }
    [[nodiscard]] T  or_value(const T& other) {
        if (_set) {
            return _value;
        }

        return other;
    }

    [[nodiscard]] T*  addr_or_null() {
        if (_set) {
            return &_value;
        }

        return nullptr;
    }

    void clear() { _set = false; }
    void set_value() { _set = true; }
    void set_value(const T& value) {
        _set   = true;
        _value = value;
    }

private:
    T    _value{};
    bool _set = false;
};

template <typename T>
inline Optional<T> optional_when(bool condition, const T& value) {
    if (condition) {
        return value;
    }
    return {};
}

