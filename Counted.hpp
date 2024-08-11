template <typename BeingCounted>
class Counted
{
public:
    class TooManyObjects{};
    static int objectCount() {
        return numObjects;
    }

protected:
    Counted();
    Counted(const Counted& rhs);
    ~Counted() { -- numObjects; }

private:
    inline static int numObjects = 0;
    static const int maxObjects;
    void init(); 
};

template <typename BeingCounted>
Counted<BeingCounted>::Counted() {
    init();
}

template <typename BeingCounted>
Counted<BeingCounted>::Counted(const Counted<BeingCounted>& rhs) {
    init();
}

template <typename BeingCounted>
void Counted<BeingCounted>::init() {
    if (numObjects >= maxObjects) {
        throw TooManyObjects();
    }
    ++ numObjects;
}
