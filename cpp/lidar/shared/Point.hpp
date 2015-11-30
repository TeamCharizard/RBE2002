template<typename T>
class Point {
private:
    T x_,y_;
public:
    Point() : x_(0), y_(0){
    }

    Point(T x, T y) : x_(x), y_(y) {
    }

    T& x() { return x_; }
    T& y() { return y_; }
};
