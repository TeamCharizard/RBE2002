template<typename T>
class Vec {
private:
    T x_,y_;
public:
    T& x() { return x_; }
    T& y() { return y_; }
};
